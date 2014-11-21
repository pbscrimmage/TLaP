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

int main(int argc, char *argv[])
{
    char outputChar;
    for (int row = 1, spaces = 3; row <= 8; row++, spaces = abs(4 - row))
    {
        for (int position = 1; position <= 8 - spaces; position++)
	{
	    if (position > spaces)
	    {
	        outputChar = '#';
	    }
	    else outputChar = ' ';

	    cout << outputChar;
	}
    cout << "\n";
    }
    return 0;
}
