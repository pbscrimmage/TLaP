/**
 * studentQuartiles.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Write a program that determines the grade quartiles for
 *      an array of student objects.
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

double findStudentQuartile(student studentArray[], int lowerBound, int upperBound)
{
    int range = upperBound - lowerBound;
    int middle = lowerBound + (range / 2);

    if (range % 2 == 0)
    {
        //average the two middle values for even-length segments
        return (studentArray[middle -1].grade + studentArray[middle].grade) / 2;
    }
    else return studentArray[middle].grade;
}

int main (int argc, char *argv[])
{
    //sort by grade
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrades);

    int half = ARRAY_SIZE / 2;
    //add 0.5 to round from double -> int
    int firstQuartile = findStudentQuartile(studentArray, 0, half) + 0.5;
    int secondQuartile = findStudentQuartile(studentArray, 0, ARRAY_SIZE) + 0.5; 
    int thirdQuartile = findStudentQuartile(studentArray, half, ARRAY_SIZE) + 0.5;

    cout << "Q1: "<< firstQuartile << "\n";
    cout << "Q2: "<< secondQuartile << "\n";
    cout << "Q3: "<< thirdQuartile << "\n";

    return 0;
}
