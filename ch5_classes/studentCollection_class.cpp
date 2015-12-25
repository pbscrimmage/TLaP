/**
 * studentCollection_class.cpp
 *
 * Author: Patrick Rummage <patrickbrummage@gmail.com>
 *
 * Objective:
 *      Create a studentCollection class to store student records as a linked
 *      list with appropriate constructor, destructor, and assignment operator,
 *      as well as methods to:
 *          Add and delete nodes
 *          Return a record given a student ID#
 *          Average all grades in the records in the list
 *          Return a new studentCollection object with a list of all records
 *              containing grades in a given range
 */
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

struct studentRecord {
    int studentID;
    int grade;
    string name;
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
        void printList() const;
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

//-----------------------------------------------------------------------------
studentCollection::studentCollection() {
    _listHead = NULL;
}

//-----------------------------------------------------------------------------
void studentCollection::printList() const {
    studentNode* listPtr = _listHead;
    if (listPtr == NULL) {
        cout << "(Empty List)";
    }
    while (listPtr != NULL) {
        cout << listPtr->studentData.studentID << ", " << listPtr->studentData.grade <<
            ", " << listPtr->studentData.name << '\n';
        listPtr = listPtr->next;
    }
}

//-----------------------------------------------------------------------------
void studentCollection::addRecord(studentRecord newStudent) {
    studentNode* newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead; // Previous first item
    _listHead = newNode;
}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
void studentCollection::deleteList(studentNode* &listPtr) {
    while (listPtr != NULL) {
        studentNode* temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
studentCollection::~studentCollection() {
    deleteList(_listHead);
}

//-----------------------------------------------------------------------------
studentCollection& studentCollection::operator=(const studentCollection& rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& ost, const studentCollection& sc) {
    sc.printList();
    
    return ost;
}

int main (int argc, char* argv[]) {
    studentCollection collection1;
    collection1.addRecord(studentRecord{0,100,"Peace"});
    collection1.addRecord(studentRecord{1,50,"Scrimbles"});

    studentCollection collection2 = collection1;
    collection2.addRecord(studentRecord{2,25,"Grizzabella"});
    collection2.addRecord(studentRecord{3,90,"Socrates"});
    collection2.addRecord(studentRecord{4,89,"Wizard"});

    studentCollection collection3 = collection2.recordsWithinRange(90,100);
    studentCollection collection4 = collection2.recordsWithinRange(0,20);

    studentRecord s1 = collection2.recordWithNumber(3);
    cout << "Record #3: " << s1.name << '\n';

    double average = collection1.averageRecord();
    double average2 = collection2.averageRecord();
    cout << average << '\n';
    cout << average2 << '\n';

    cout << collection2 << '\n';
    cout << collection3 << '\n';
    cout << collection4 << '\n';

    collection2.removeRecord(3);
    cout << '\n' << collection2 << '\n';

    return 0;
}
