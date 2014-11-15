/*
* Upsidedown_pyramid.cpp
* 
* Prints out an upside down pyramid shape in hashes
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
