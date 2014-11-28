/**
 * linkedStudents.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Given a linked list of student structures and functions to add records
 *      and average grades, define a function to delete a node from the list by 
 *      student number.
 */
#include <iostream>
using std::cin;
using std::cout;

struct listNode {
    int studentNum;
    int grade;
    listNode *next;
};
typedef listNode *studentCollection;

void addRecord(studentCollection &sc, int stuNum, int gr);
double averageRecord(studentCollection sc);
void removeRecord(studentCollection &sc, int stuNum);
        
int main(int argc, char *argv[])
{
    studentCollection sc; //Head pointer
    listNode *node1 = new listNode; //Create nodes
    node1->studentNum = 1001; node1->grade = 78;
    listNode *node2 = new listNode;
    node2->studentNum = 1012; node2->grade = 93;
    listNode *node3 = new listNode;
    node3->studentNum = 1076; node3->grade = 85;
    sc = node1; //Point sc to first node, link the others
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    
    /*Test removeRecord();*/
    removeRecord(sc, 1001);
    listNode *loopPtr = sc;
    while (loopPtr != NULL) {
        cout << loopPtr->studentNum << "\n";
        loopPtr = loopPtr->next;
    }
}

/*Creates new student node at beginning of studentCollection*/
void addRecord(studentCollection &sc, int stuNum, int gr)
{
    listNode *newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc; //Point next at previous node1 
    sc = newNode; //Point head at new node
}

/*Deletes student node by student number*/
void removeRecord(studentCollection &sc, int stuNum)
{
    if (sc == NULL) //Empty list
        return;
    listNode *loopPtr = sc;
    listNode *previous = sc;
    while (loopPtr != NULL) {
        if (loopPtr->studentNum == stuNum) {
            if (loopPtr == sc) //If removing first node
                sc = loopPtr->next; //reassign head pointer
            else
                previous->next = loopPtr->next; //link past this node
            delete loopPtr;
        }
        previous = loopPtr;
        loopPtr = loopPtr->next;
    }    
}

/*Returns average of grade fields in studentCollection*/
double averageRecord(studentCollection sc)
{
    if (sc == NULL) //Empty list
        return 0;
    int count = 0;
    double sum = 0;
    listNode *loopPtr = sc;
    while (loopPtr != NULL) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = sum / count;
    return average;
}
