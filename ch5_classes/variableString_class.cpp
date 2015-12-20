/**
 * variableString_class.cpp
 *
 * Author: Patrick Rummage <patrickbrummage@gmail.com>
 *
 * Objective:
 *      Create a class to represent variable-length strings which has methods
 *      to append a char, to concatenate two strings, to remove a sequence of chars, 
 *      and to return the char at a given position.
 */
#include <iostream>
using std::cin;
using std::cout;

class variableString {
    public:
        variableString();
        ~variableString();
        variableString(const char* s);

        char characterAt(int pos) { return _s[pos]; }
        int getlength() { return _length; }
        void append(char c);
        void concatenate(const variableString& s2);
        void remove(int start, int end);

    private:
        char * _s; // pointer to beginning of array
        int _length;
};

//--------------------------------------------------------
variableString::variableString() {
    _s = NULL;
    _length = 0;
}

//--------------------------------------------------------
variableString::variableString(const char* s) {
    int strlen = 0;
    int i = 0;
    while (s[i] != 0){
        strlen++;
        i++;
    }
    _s = new char[strlen + 1]; // extra space for null
    for (int i = 0; i < strlen; i++){
        _s[i] = s[i];
    }
    _s[strlen] = 0; // null terminate
    _length = strlen;
}

//--------------------------------------------------------
void variableString::append(char c) {
    char * newS = new char[_length + 2];
    for (int i = 0; i < _length; i++) {
        newS[i] = _s[i];
    }
    newS[_length] = c;
    newS[_length+1] = 0;
    delete[] _s;
    _s = newS;
    _length++;
}

//--------------------------------------------------------
void variableString::concatenate(const variableString& s2) {

}

//--------------------------------------------------------
void variableString::remove(int start, int end) {

}

//--------------------------------------------------------
variableString::~variableString() {
    delete[] _s;
}


int main(int argc, char* argv[]) {

    //Test initializer
    variableString s1{"test string"};

    //Test append
    s1.append('!');

    return 0;
}

