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

        char* getstring() { return _s; }
        char characterAt(int pos) { return _s[pos]; }
        int getlength() { return _length; }
        void append(char c);
        void concatenate(variableString& s2);
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
void variableString::concatenate(variableString& s2) {
    int newlength = _length + s2.getlength();
    char* newS = new char[newlength + 1];
    for (int i = 0; i < _length; i++) {
        newS[i] = _s[i]; // copy first part
    }
    char* end = s2.getstring();
    for (int j = _length, k = 0; j < newlength; j++, k++) {
        newS[j] = end[k]; // copy second part
    }
    newS[newlength] = 0;
    delete[] _s;
    _s = newS;
    _length = newlength;
}

//--------------------------------------------------------
void variableString::remove(int start, int delnum) {
    int newlength = _length - delnum;
    char* newS = new char[newlength]; 
    for (int i = 0, j = 0; i < _length; i++) {
        if (i < start || i >= start + delnum) {
            newS[j] = _s[i];
            j++;
        }
    }
    newS[newlength] = 0;
    delete[] _s;
    _s = newS;
    _length = newlength;
}

//--------------------------------------------------------
variableString::~variableString() {
    delete[] _s;
}

std::ostream& operator<<(std::ostream& ost, variableString& s) {
    char* ptr = s.getstring();
    ost << ptr;
    return ost;
}

int main(int argc, char* argv[]) {

    //Test initializer
    variableString s1{"test string"};
    cout << "===Testing Initializer===" << '\n';
    cout << s1 << '\n';

    //Test append
    cout << "===Testing Append===" << '\n';
    s1.append('!');
    cout << s1 << '\n';

    //Test concatenate
    variableString s2{"new ending"};
    cout << "===Testing Concatenate===" << '\n';
    s1.concatenate(s2);
    cout << s1 << '\n';

    //Test remove
    cout << "===Testing Remove===" << '\n';
    s1.remove(12,3);
    cout << s1 << '\n';

    return 0;
}
