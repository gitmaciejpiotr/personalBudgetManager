#include "HelpfulMethods.h"


string HelpfulMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelpfulMethods::getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string HelpfulMethods::tranformFirstLeterIntoBigOneAndTheRestIntoSmallOnes(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string HelpfulMethods::getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition ++;
    }
    return number;
}

int HelpfulMethods::convertStringToInt(string number)
{
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

char HelpfulMethods::setCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "It is not a single character. Please type again." << endl;
    }
    return character;
}

int HelpfulMethods::setInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest number. Wpisz ponownie. " << endl;
    }
    return number;
}
