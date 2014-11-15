/**
* baseConvert.cpp
*
* Author: Patrick Rummage (patrickbrummage@gmail.com)
*
* Takes a positive number in decimal, binary, hex, or octal form and 
* converts the number to the other 3 forms.
*/
#include <iostream>
using std::cin;
using std::cout;

int convertToDecimal(int base);
void baseConvert(int number, int base);
int findNearestPower(int number, int base);

int main(int argc, char *argv[])
{
    char mode;
    cout << "Choose input mode. [d]ecimal, [o]ctal, [h]ex, [b]inary: ";
    mode = cin.get();
    cin.ignore(1); //ignore ENTER

    int decimalNum;
    switch(mode)
    {
	case 'd':
	//decimal
	    cout << "Enter number: ";
	    cin >> decimalNum;
	    cout << "Binary: ";
	    baseConvert(decimalNum, 2);
	    cout << "Octal: ";
	    baseConvert(decimalNum, 8);
	    cout << "Hexadecimal: ";
	    baseConvert(decimalNum, 16);
	    break;
	case 'b':
	//binary
	    decimalNum = convertToDecimal(2);
	    cout << "Decimal: " << decimalNum << "\n";
	    cout << "Octal: ";
	    baseConvert(decimalNum, 8);
	    cout << "Hexadecimal: ";
	    baseConvert(decimalNum, 16);
	    break;
	case 'o':
	//octal
	    decimalNum = convertToDecimal(8);
	    cout << "Decimal: " << decimalNum << "\n";
	    cout << "Binary: ";
	    baseConvert(decimalNum, 2);
	    cout << "Hexadecimal: ";
	    baseConvert(decimalNum, 16);
	    break;
	case 'h':
	//hex
	    decimalNum = convertToDecimal(16);
	    cout << "Decimal: " << decimalNum << "\n";
	    cout << "Binary: ";
	    baseConvert(decimalNum, 2);
	    cout << "Octal: ";
	    baseConvert(decimalNum, 8);
	    break;
    }

    return 0;
}

int convertToDecimal(int base)
{
    char digit;
    int decimalNum = 0;
    cout << "Enter number: ";
    digit = cin.get();

    while (digit != 10)
    {
	decimalNum *= base;

	if (digit >= 'a') //hex lowercase
	{
	    decimalNum += (digit - 87);
	}
	else if (digit >= 'A') //hex uppercase
	{
	    decimalNum += (digit - 55);
	}
	else decimalNum += (digit - '0');

	digit = cin.get();
    }
    return decimalNum;
}

void baseConvert(int number, int base)
{
    int nearestPower = findNearestPower(number, base);
    int subtract;
    int nextChar;
    char outputChar;

    while (nearestPower >= 1)
    {
	subtract = number - nearestPower;
	if (subtract >= 0)
	{
	    nextChar = (number / nearestPower) % base;
            switch(nextChar)
	    {
	        case 10: outputChar = 'A'; break;
		case 11: outputChar = 'B'; break;
		case 12: outputChar = 'C'; break;
		case 13: outputChar = 'D'; break;
		case 14: outputChar = 'E'; break;
		case 15: outputChar = 'F'; break;
		default:
		    outputChar = nextChar + '0';
	    }
	    number = subtract;
	    nearestPower /= base;
        }
	else
	{
	    outputChar = '0';
	    nearestPower /= base;
	}

	cout << outputChar;
    }
    cout << "\n";
}

int findNearestPower(int number, int base)
{
    int power = 1;
    while (power < number)
    {
	power *= base;
    }
    if (power > number)
    {
	return power / base;
    }
    else return power;
}
