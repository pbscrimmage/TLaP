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
typedef stringNode *string; //Use for head

void append(string &s, char c);
char characterAt(string s, int index);

int main(int argc, char *argv[])
{
    string s = NULL; //Head pointer to empty list

    /*Test append()*/
    cout << "Enter a string: ";
    char inputChar = cin.get();
    while (inputChar != 10) { //Append input chars to s
        append(s, inputChar);
        inputChar = cin.get();
    }
    stringNode *loopPtr = s;
    while (loopPtr != NULL) { //Print s
        cout << loopPtr->c;
        loopPtr = loopPtr->next;
    }
    cout << "\n";

    /*Test characterAt()*/
    int position;
    cout << "Enter a character position: ";
    cin >> position;
    cout << characterAt(s, position) << "\n";
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

char characterAt(string s, int index)
{
    if (s == NULL) { //Empty list
        return -1;
    }
    stringNode *loopPtr = s;
    for (int i = 0; i <= index; i++) {
        if (i == index) {
            return loopPtr->c;
        }
        if (loopPtr->next == NULL) { //End of list
            return -1;
        }
        loopPtr = loopPtr->next;
    }
}

