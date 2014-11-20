/**
 * isSorted.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Define a function of type 'bool' that determines whether an array is sorted.
 *      Must do so in a single pass.
 */
#include <iostream>
using std::cin;
using std::cout;

const int NUM_ARRAYS = 3;
const int ARRAY_SIZE = 10;
int tests[NUM_ARRAYS][ARRAY_SIZE] = {
    {0, 1, 2, 4, 3, 5, 6, 7, 8, 9},
    {100, 111, 204, 543, 544, 545, 1006, 2777, 2848, 4009},
    {-1, 1, 2, 3, 4, 5, 6, 7, 9, 8}
};

bool isSorted(int array[], int arraySize)
{
    int previous = array[0];
    for (int position = 1; position < arraySize; position++)
    {
        if (array[position] < previous)
        {
            return false;
        }
        previous = array[position];
    }
    return true;
}

int main (int argc, char *argv[])
{
    for (int i = 0; i < NUM_ARRAYS; i++)
    {
        cout << "Test array " << i + 1 << ": " << isSorted(tests[i], ARRAY_SIZE)
           << "\n"; 
    }
    return 0;
}
