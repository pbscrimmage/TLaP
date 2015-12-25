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
    char* name;
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
        double averageRecord();
        studentCollection recordsWithinRange(int low, int high);
        void removeRecord(int idNum);
        studentNode* copiedList(const studentNode* original);
        studentCollection& operator=(const studentCollection& rhs);

    private:
        studentNode* _listHead;
        void deleteList(studentNode* &listPtr);
};

studentCollection::studentCollection() {
    _listHead = NULL;
}

void studentCollection::addRecord(studentRecord newStudent) {
    studentNode* newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead; // previous first item
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum) {
    studentNode* loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.studentID != idNum) {
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) {
        studentRecord dummyRecord{-1,-1,"VOID"};
        return dummyRecord;
    } else {
        return loopPtr->studentData;
    }
}

double studentCollection::averageRecord() {
    if (_listHead == NULL) { // Handle empty list
        return 0;
    }
    int count = 0;
    int sum = 0;
    studentNode* listPtr = _listHead;
    while (listPtr != NULL) {
       sum += listPtr->studentData.grade;
       count++;
       listPtr = listPtr->next;
    }
    double average = sum / count; 
    return average;
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

void studentCollection::deleteList(studentNode* &listPtr) {
    while (listPtr != NULL) {
        studentNode* temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

studentCollection studentCollection::recordsWithinRange(int low, int high) {
    studentCollection newCollection;
    studentNode* listPtr = _listHead;
    int studentGrade;
    while (listPtr != NULL) {
        studentGrade = listPtr->studentData.grade; 
        if (studentGrade >= low && studentGrade <= high) {
           newCollection.addRecord(listPtr->studentData); 
        }
        listPtr = listPtr->next;
    }
    return newCollection;
}

studentCollection::studentNode*
studentCollection::copiedList(const studentNode* original) {
    if (original == NULL) {
        return NULL;
    }
    studentNode* newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode* oldLoopPtr = original->next;
    studentNode* newLoopPtr = newList;
    while(oldLoopPtr != NULL) {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    newLoopPtr->next = NULL;
    return newList;
}

studentCollection::~studentCollection() {
    deleteList(_listHead);
}

studentCollection& studentCollection::operator=(const studentCollection& rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

int main (int argc, char* argv[]) {

    return 0;
}
