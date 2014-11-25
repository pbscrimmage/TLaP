/**
* diamond.cpp
*
* Objective:
*       Print out a diamond shape in hashes using two output
*       statements.
*
* 	    ##
* 	   ####
* 	  ######
* 	 ########
* 	 ########
* 	  ######
* 	   ####
* 	    ##
*/
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;

const int NUM_ROWS = 8;

int main(int argc, char *argv[])
{
    int numSpaces;
    int rowLength;
    for (int row = 1; row <= NUM_ROWS; row++)
    {
        numSpaces = (int)abs(4.5 - row);
        rowLength = NUM_ROWS - numSpaces;
        for (int position = 1; position <= rowLength; position++)
        {
            if (position <= numSpaces)
            {
                cout << " ";
            }
            else cout << "#";
        }
    cout << "\n";
    }
    return 0;
}
