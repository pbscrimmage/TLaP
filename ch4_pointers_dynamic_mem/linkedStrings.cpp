/**
 * linkedStrings.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Implement a string type using a linked list of chars. Define
 *      functions to append and to retrieve a char at an index.
 */
#include <iostream>
using std::cin;
using std::cout;

struct stringNode {
    char c;
    stringNode *next;
};
typedef stringNode *string;

void append(string &s, char c);

int main(int argc, char *argv[])
{
    string s = NULL; //Head pointer to empty list
    cout << "Enter a string: ";
    char inputChar = cin.get();
    while (inputChar != 10) { //append input chars to s
        append(s, inputChar);
        inputChar = cin.get();
    }
    stringNode *loopPtr = s;
    while (loopPtr != NULL) { //print s
        cout << loopPtr->c;
        loopPtr = loopPtr->next;
    }
    cout << "\n";
}

void append(string &s, char c)
{
    stringNode *newNode = new stringNode;
    newNode->c = c;
    newNode->next = NULL;
    if (s == NULL) { //Empty list
        s = newNode;
        return;
    }
    stringNode *loopPtr = s;
    while (loopPtr != NULL) {
        if (loopPtr->next == NULL) { //Last node
            loopPtr->next = newNode;
            return;
        }
        loopPtr = loopPtr->next;
    }
}
