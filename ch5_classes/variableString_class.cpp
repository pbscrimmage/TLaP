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
#include <string>
using namespace std;

class variableString {
    public:
        variableString();
        ~variableString();
        variableString(const string& s2);

        char characterAt(int pos) { return _s[pos]; }
        int getlength() { return _length; }
        void append(char c);
        void concatenate(const variableString& s);
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
variableString::variableString(const string& s) {
    int strlen = s.length();
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
