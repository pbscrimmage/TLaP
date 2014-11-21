/**
 * medianSales.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Use a two-dimensional array of sales data to identify the sales agent 
 *      with the highest median sales figure in a year.
 */
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;
int sales[NUM_AGENTS][NUM_MONTHS] = {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 
        276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122,
        7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
};

int compare(const void *p1, const void *p2)
{
    int x = *(int *)p1,
        y = *(int *)p2;
    return x <= y ? (x < y ? -1 : 0) : 1; 
}

double findMedian(int intArray[], int ARRAY_SIZE)
{
    qsort(intArray, ARRAY_SIZE, sizeof(int), compare);
    int middle = ARRAY_SIZE / 2;
    
    //arrays all have even # of elements (12), so average the two middle numbers
    //add 0.5 to round    
    return ((intArray[middle - 1] + intArray[middle]) / 2) + 0.5;       
}

int main(int argc, char *argv[])
{
    int bestAgent = 0;
    int highestMedian = findMedian(sales[0], 12);
    for (int agent = 1; agent < NUM_AGENTS; agent++)
    {
        int agentMedian = findMedian(sales[agent], 12);
        if (agentMedian > highestMedian)
        {
            highestMedian = agentMedian;
            bestAgent = agent;
        }
    }
    cout << "Agent " << bestAgent << " had best median sales: " <<
       highestMedian << "\n"; 
    
    return 0;
}
