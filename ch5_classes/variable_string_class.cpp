#include <iostream>

using namespace std;

class VarString {
    public:
        VarString();
        VarString(const char* init);
        ~VarString();
        int length() const;
        void append(char c);
        void concatenate(const VarString& s2);
        char operator[](int pos) const;
        VarString& operator=(const VarString& rhs);
    private:
        typedef char* string;
        string _s;
};

VarString::VarString()
{
    _s = new char[1] {0};
}

VarString::VarString(const char* init)
{
    int count = 0;
    for (int i = 0; init[i] != 0; i++) {
       count++;
    } 
    string newS = new char[count];
    for (int i = 0; init[i] != 0; i++) {
        newS[i] = init[i];
    }
    _s = newS;
}

int VarString::length() const
{
    int count = 0;
    while (_s[count] != 0) {
        count++;
    }
    return count;
}

char VarString::operator[](int pos) const
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
    int s1_oldLength = this->length();
    int s2_length = s2.length();
    int s1_newLength = s1_oldLength + s2_length;
    string newS = new char[s1_newLength + 1];
    for (int i = 0; i < s1_oldLength; i++) {
        newS[i] = _s[i];
    }
    for (int i = 0; i < s2_length; i++) {
        newS[s1_oldLength + i] = s2._s[i];
    }
    newS[s1_newLength] = 0;
    delete[] _s;
    _s = newS;
}

VarString& VarString::operator=(const VarString& rhs)
{   
    int length = rhs.length() + 1;
    string copy = new char[length];
    for (int i = 0; i < length; i++) {
        copy[i] = rhs._s[i];
    }
    copy[length] = 0;
    _s = copy;
    delete[] copy;
    
    return *this;
}

ostream& operator<<(ostream& ost, const VarString& rhs)
{
    for (int i = 0; rhs[i] != 0; i++) {
        ost << rhs[i];
    }
    return ost;
}

VarString::~VarString()
{
    delete[] _s;
}

int main()
{   //Test all methods
    VarString s1("This is a variable string");
    VarString s2;
    s2.concatenate(s1);

    cout << s1 << '\n';
    cout << s2 << '\n';
    
    return 0;
}
