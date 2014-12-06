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

void append(lengthString &s, char c);
char characterAt(lengthString s, int position);
void concatenate(lengthString &s1, lengthString s2);
void replaceString(lengthString &s, lengthString target, lengthString replaceText);
bool stringEqual(lengthString s1, lengthString s2);
lengthString substring(lengthString s, int position, int length);


void input(lengthString &s)
{

    char inputChar = cin.get();
    while (inputChar != 10) {
        append(s, inputChar);
        inputChar = cin.get(); 
    }
}
void output(lengthString s)
{
    int length = s[0];
    for(int i = 1; i <= length; i++) {
        cout << s[i];
    }
    cout << "\n";
}

int main(int argc, char *argv[])
{
    //Test append()
    cout << "**TESTING append**\n";
    lengthString string1 = new char[0];
    cout << "Enter a string: ";
    input(string1);
    output(string1);

    //Test concatenate()
    cout << "**TESTING concatenate**\n";
    lengthString string2 = new char[0];
    cout << "Enter another string: ";
    input(string2);
    output(string2);
    concatenate(string1, string2);
    output(string1);

    //Test substring()
    cout << "**TESTING subString**\n";
    lengthString subString = substring(string1, 3, 4);
    output(subString);

    //Test replaceString()
    cout << "**TESTING replaceString**\n";
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

char characterAt(lengthString s, int position)
{
    return s[position + 1];
}

void append(lengthString &s, char c)
{
    int oldLength = s[0];
    int newLength = oldLength + 1;
    lengthString newS = new char[newLength + 1];
    newS[0] = newLength;
    for (int i = 1; i <= newLength; i++) {
        if (i == newLength)
            newS[i] = c;
        else
           newS[i] = s[i];
    }
    delete[] s;
    s = newS;
}

void concatenate(lengthString &s1, lengthString s2)
{
    int s1_length = s1[0];
    int s2_length = s2[0];
    int newLength = s1_length + s2_length;
    lengthString newS = new char[newLength + 1];
    newS[0] = newLength;
    for (int i = 1; i <= s1_length; i++) {
        newS[i] = s1[i];
    }
    for (int i = 1; i <= s2_length; i++) {
        newS[s1_length + i] = s2[i];
    }
    delete[] s1;
    s1 = newS;
}

bool stringEqual(lengthString s1, lengthString s2)
{
    int s_length = s1[0];
    for (int i = 1; i <= s_length; i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

lengthString substring(lengthString s, int position, int length)
{
    lengthString sub = new char[length + 1];
    sub[0] = length;
    for (int i = 0; i < length; i++) {
        sub[1 + i] = s[position + i];
    }
    return sub;
}
/*Problems when replace < target*/
void replaceString(lengthString &s, lengthString target, lengthString replaceText)
{
    int s_length = s[0];
    int targetLength = target[0];
    int replaceLength = replaceText[0];
    for (int i = 1; i <= s_length; i++) {
        if (s[i] == target[1] && 
                stringEqual(substring(s, i, targetLength), target)) {
 
            int newLength = s_length + (replaceLength - targetLength);
            /*Allocate and create new string*/
            lengthString newS = new char[newLength];
            lengthString begin = substring(s, 1, i - 1);
            lengthString end = substring(s, i + targetLength, s_length - (i - 1 + targetLength));
            concatenate(newS, begin); //Original beginning
            concatenate(newS, replaceText); //Replace stuff
            concatenate(newS, end); //Original end
            delete[] s;
            s = newS; 
            s_length = s[0]; //In case length was changed by replace
        }
    }
}

