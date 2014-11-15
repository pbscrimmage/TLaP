/**
* diamond.cpp
*
* Prints out a diamond shape in hashes
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
    cout << "Press any key to exit: ";
    cin.get();
    return 0;
}
