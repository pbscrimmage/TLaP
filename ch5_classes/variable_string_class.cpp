#include <iostream>

using std::cin;
using std::cout;

class VarString {
    public:
        VarString() {};
        VarString(char* init);
        ~VarString();
        int length();
        char characterAt(int pos);
        void append(char c);
        void concatenate(const VarString s2);
    private:
        typedef char* string;
        string _s;
};

int VarString::length()
{
    int count = 0;
    while (_s[count] != 0) {
        count++;
    }
    return count;
}

char VarString::characterAt(int pos)
{
    return _s[pos];
}

void VarString::append(char c)
{
    int oldLength = 0;
    while (_s[oldLength] != 0) {
        oldLength++;
    }
    string newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; i++) {
        newS[i] = _s[i];
    }
    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] _s;
    _s = newS;
}

void VarString::concatenate(const VarString& s2)
{
    int s1_oldLength = length(_s);
    int s2_length = length(s2);
    int s1_newLength = s1_oldLength + s2_length;
    string newS = new char[s1_newLength + 1];
    for (int i = 0; i < s1_oldLength; i++) {
        newS[i] = _s[i];
    }
    for (int i = 0; i < s2_length; i++) {
        newS[s1_oldLength + i] = s2[i];
    }
    newS[s1_newLength] = 0;
    delete[] _s;
    _s = newS;
}

int main()
{
    
    return 0;
}
