/**
 * sortStudents.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Use qsort to sort an array of student data structures. Sort first by
 *      the grade field, then by the student ID field.
 */
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct student
{
    int grade;
    int studentID;
    string name;
};

const int ARRAY_SIZE = 10; 
student studentArray[ARRAY_SIZE] = 
{
    {87, 10001, "Fred"}, 
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"}, 
    {84, 10005, "Erin"}, 
    {98, 10006, "Belinda"}, 
    {75, 10007, "Leslie"}, 
    {70, 10008, "Candy"}, 
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"} 
};

int compareGrades(const void *p1, const void *p2)
{
    int x = ((const struct student *)p1)->grade,
        y = ((const struct student *)p2)->grade;
    return x <= y ? (x < y ? -1 : 0) : 1;
}

int compareIDs(const void *p1, const void *p2)
{
    int x = ((const struct student *)p1)->studentID,
        y = ((const struct student *)p2)->studentID;
    return x <= y ? (x < y ? -1 : 0) : 1;
}   

int main (void)
{
    //sort by grades
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrades);
    cout << "Grades: ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].grade << " ";
    }
    cout << "\n";

    //sort by studentIDs
    cout << "Student IDs: ";
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareIDs);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].studentID << " ";
    }
    cout << "\n";

    return 0;
}
