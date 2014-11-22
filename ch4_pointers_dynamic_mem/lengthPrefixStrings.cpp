/**
 * lengthPrefixStrings.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Implement a string type that stores its length at location[0]. 
 *      Create functions to append, concatenate, and locate characters
 *      within strings of this type.
 */
#include <iostream>
using std::cin;
using std::cout;

typedef char *lengthString;

char characterAt(lengthString s, int position)
{
    return s[position + 1];
}

void append(lengthString &s, char c)
{
    int oldLength = s[0];
    s[oldLength + 1] = c;
    s[0] = oldLength + 1;
}

void concatenate(lengthString &s1, lengthString s2)
{
    int s1_length = s1[0];
    int s2_length = s2[0];
    int s1_newLength = s1_length + s2_length;
    for (int i = 1; i <= s2_length; i++)
    {
        s1[s1_length + i] = s2[i];
    }
    s1[0] = s1_newLength;
}

void output(lengthString s)
{
    int length = s[0];
    for(int i = 1; i <= length; i++)
    {
        cout << s[i];
    }
    cout << "\n";
}

int main(int argc, char *argv[])
{
    lengthString input1 = new char[0];
    cout << "Enter a string: ";
    char inputChar = cin.get();
    while (inputChar != 10)
    {
        append(input1, inputChar);
        inputChar = cin.get(); 
    }
    output(input1);
    
    lengthString input2 = new char[0];
    cout << "Enter another string: ";
    inputChar = cin.get();
    while (inputChar != 10)
    {
        append(input2, inputChar);
        inputChar = cin.get(); 
    }
    concatenate(input1, input2);
    output(input1);
    
    return 0;
}

