/*
* Upsidedown_pyramid.cpp
* 
* Objective:
*       Print out an upside down pyramid shape in hashes using
*       one output statement each for hashes, spaces, and newlines.
* 
* 	########
* 	 ######
* 	  ####
* 	   ##
*/
#include <iostream>
using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
    char outputChar;
    for (int row = 1, spaces = 0; row <= 4; row++, spaces++)
    {
	for (int position = 1; position <= 8 - spaces; position++)
	{
	    if (position > spaces)
	    {
	    	cout << '#';
	    }
	    else cout << ' ';
	}
	cout << "\n";
    }
    return 0;
}
