/**
 * substitutionCipher.cpp
 *
 * Author: Patrick Rummage (patrickbrummage@gmail.com)
 *
 * Objective:
 *      Use a const array of chars to create a substitution cipher to
 *      encrypt and decrypt messages.
 */
#include <string>
#include <iostream>
using namespace std;

const int NUM_CHARS = 26;
const char CIPHER_CHARS[NUM_CHARS] = 
{'Z', 'C', 'F', 'A', 'L', 'R', 'P', 'B', 'Q', 'E', 'Y', 'U', 'O', 'X', 'T', 'G',
    'I', 'V', 'K', 'H', 'D', 'S', 'N', 'J', 'W', 'M'};

int findChar(char target)
{
    for (int i = 0; i < NUM_CHARS; i++)
    {
        if (CIPHER_CHARS[i] == target)
            return i;
    }
}

int main(int argc, char *argv[])
{
    char mode;
    cout << "Choose mode. [E]ncrpyt or [D]ecrypt ";
    cin >> mode;
    cin.ignore(1); //ignore ENTER
    string message;
    cout << "Enter text: ";
    getline(cin, message);

    int textLength = message.length();
    //ENCRYPT
    if (mode == 'E' || mode == 'e')
    {
        char cipherChar;
        for (int i = 0; i < textLength; i++)
        {
            //capital letters
            if (message[i] >= 'A' && message[i] <= 'Z')
            {
                cipherChar = CIPHER_CHARS[ message[i] - 'A' ];
            }
            //lowercase letters
            if (message[i] >= 'a' && message[i] <= 'z')
            {
                cipherChar = CIPHER_CHARS[ message[i] - 'a' ];
            }
            //punctuation
            else
                cipherChar = message[i];

            cout << cipherChar;
        }
        cout << "\n";
    }
    //DECRYPT
    else if (mode == 'D' || mode == 'd')
    {
        char plainChar;
        for (int i = 0; i < textLength; i++)
        {
            //letters
            char letter = toupper(message[i]);
            if (letter >= 'A' && letter <= 'Z')
            {
                int charPosition = findChar(letter);
                plainChar = charPosition + 'A';
            }
            //punctuation
            else
                plainChar = message[i];

            cout << plainChar;
        }
        cout << "\n";
    }
    return 0;
}
