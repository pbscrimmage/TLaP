/**
* isbn_checksum.cpp
*
* Author: Patrick Rummage (patrickbrummage@gmail.com)
*
* Calculates checksum to validate a 10 or 13 digit ISBN number.
*/
#include <iostream>
using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
	char digit;
	int checksum = 0;
	int digitCount = 1;

	cout << "Enter number to validate: ";
	digit = cin.get();

	//process digits until ENTER (ASCII 10)
	while (digit != 10)
	{
		if (digitCount % 2 == 0)
		{
			checksum += (digit - '0') * 3;
		}
		else
		{
			checksum += (digit - '0');
		}
		digit = cin.get();
		digitCount++;
	}
	//fix to convert 10 digit (pre 2007) number to 13 digit number
	//standard prefix is 978. (9 + 14 + 8 = 31)
	if (digitCount == 10)
	{
		checksum += 31;
	}
	//validate checksum
	cout << "Checksum is: " << checksum << ".\n";
	if (checksum % 10 == 0)
	{
		cout << "VALID. Checksum is a multiple of 10.";
	}
	else
	{
		cout << "INVALID. Checksum is not a multiple of 10.";
	}
	cout << "Press any key to exit";
	cin.get();
	return 0;
}
