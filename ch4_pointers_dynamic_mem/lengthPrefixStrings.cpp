/**
 * lengthPrefixStrings.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Implement a string type that stores its length at location[0]. 
 *      Define functions to append, concatenate, create substrings, and 
 *      retrieve characters from strings of this type.
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
    int newLength = s1_length + s2_length;
    lengthString newS = new char[newLength + 1];
    newS[0] = newLength;
    for (int i = 1; i <= s1_length; i++)
    {
        newS[i] = s1[1];
    }
    for (int i = 1; i <= s2_length; i++)
    {
        s1[s1_length + i] = s2[i];
    }
    delete[] s1;
    s1 = newS;
}

lengthString substring(lengthString s, int position, int length)
{
    lengthString sub = new char[length + 1];
    sub[0] = length;
    for (int i = 1; i <= length; i++)
    {
        sub[i] = s[position + i];
    }
    return sub;
}
//BROKEN!!
void replaceString(lengthString &s, lengthString target, lengthString replaceText)
{
    int s_length = s[0];
    int target_length = target[0];
    int replace_length = replaceText[0];
    int matchPosition = 0;
    for (int pos = 1; pos <= s_length; pos++)
    {
        if (s[pos] == target[1])
        {
            matchPosition = s[pos];
        }
    }
    if (matchPosition > 0)
    {
        lengthString matchString = substring(s, matchPosition, target_length);
        if (matchString == target)
        {
            for (int i = 1; i <= replace_length; i++)
            {
                s[matchPosition + i] = replaceText[i];
            }
        }
    }
}

void input(lengthString &s)
{

    char inputChar = cin.get();
    while (inputChar != 10)
    {
        append(s, inputChar);
        inputChar = cin.get(); 
    }
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
    //Test append()
    lengthString string1 = new char[0];
    cout << "Enter a string: ";
    input(string1);
    output(string1);

    //Test concatenate()
    lengthString string2 = new char[0];
    cout << "Enter another string: ";
    input(string2);
    concatenate(string1, string2);
    output(string1);

    //Test substring()
    lengthString subString = substring(string1, 3, 4);
    output(subString);

    //Test replaceString
    lengthString find = new char[0];
    lengthString replace = new char[0];
    cout << "Enter a string to find: ";
    input(find);
    cout << "Replace with: ";
    input(replace);
    replaceString(string1, find, replace);
    output(string1);
    
    return 0;
}

