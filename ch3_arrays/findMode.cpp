/**
 * findMode.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      write a program that is given an array of integers and 
 *      determines the mode, the number occurring most frequently.
 */
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;

const int ARRAY_SIZE = 20;
int test[ARRAY_SIZE] = {4,4,5,1,3,2,4,2,3,3,9,8,4,7,4,6,0,9,7,0};

int compare(const void *p1, const void *p2)
{
    int x = *(int *)p1,
        y = *(int *)p2;
    return x <= y ? (x < y ? -1 : 0) : 1;
}

int main(int argc, char*argv[])
{
    qsort(test, ARRAY_SIZE, sizeof(int), compare);
    int mode = test[0];
    int count = 1;
    int maxCount = 1;
    for (int position = 0; position < ARRAY_SIZE; position++)
    {
        if (count > maxCount)
        {
            mode = test[position];
            maxCount = count;
        }
        else if (test[position] != test[position - 1])
        {
            count = 1;
        }
        else count++;
    }
    if (maxCount == 1)
        cout << "No Mode\n";
    else 
    {
        cout << "Mode is " << mode << ", which occurs " << maxCount 
            << " times." << "\n";
    }
    return 0;
}

