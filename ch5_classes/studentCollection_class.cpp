/**
 * studentCollection_class.cpp
 *
 * Author: Patrick Rummage <patrickbrummage@gmail.com>
 *
 * Objective:
 *
 */
#include <iostream>
using std::cin;
using std::cout;

struct studentRecord {
    int studentID;
    int grade;
    char[] Name;
};

class studentCollection {
    private:
        struct studentNode {
            studentRecord studentData;
            studentNode* next;
        };

    public:
        studentCollection();
        ~studentCollection();
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);

    private:
        studentNode* _listHead;
        void deleteList(studentList &listPtr);
};

studentCollection::studentCollection() {
    _listHead = NULL;
}

void studentCollection::addrecord(studentRecord newStudent) {
    studentNode* newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead; // previous first item
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum) {
    studentNode* loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.student.studentID != idNum) {
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) {
        studentRecord dummyRecord(-1,-1,"");
        return dummyRecord;
    } else {
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(int idNum) {
    studentNode* loopPtr = _listHead;
    studentNode* previous = NULL;
    while (loopPtr != NULL && loopPtr->studentData.studentID != idNum) {
        previous = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) { // Not found
        return;
    }
    if (previous == NULL) { // Removing first node
        _listHead = _listHead->next;
    } else { // Join nodes before and after one to be deleted
        previous->next = loopPtr->next;
    }
    delete loopPtr;
}

void studentCollection::deleteList(studentList &listPtr) {
    while (listPtr != NULL) {
        studentNode* temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

studentCollection::~studentCollection() {
    deleteList(_listHead);
}
