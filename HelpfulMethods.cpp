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
        cout << "Nie wpisano jednego znaku." << endl << endl;
        cout << "Wpisz ponownie: ";
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

int HelpfulMethods::convertStringDateToIntDate(string dateString)
{
    string buffer = dateString;
    string dateInNumber;

    dateInNumber = dateString.erase(4, 9);
    dateString = buffer;

    dateString.erase(0, 5);
    dateInNumber += dateString.erase(2, 5);
    dateString = buffer;

    dateInNumber += dateString.erase(0, 8);

    return convertStringToInt(dateInNumber);
}

int HelpfulMethods::getDayIntFromStringDate(string dateString)
{
    string dayString = dateString.erase(0, 8);

    return convertStringToInt(dayString);
}

int HelpfulMethods::getMonthIntFromStringDate(string dateString)
{
    dateString.erase(0, 5);
    string monthString = dateString.erase(2, 5);

    return convertStringToInt(monthString);
}

int HelpfulMethods::getYearIntFromStringDate(string dateString)
{
    string yearString = dateString.erase(4, 9);

    return convertStringToInt(yearString);
}

string HelpfulMethods::convertIntDateToStringDate(int date)
{
    string dateString = convertIntToString(date);

    dateString.insert(4, "-");
    dateString.insert(7, "-");

    return dateString;
}

float HelpfulMethods::convertStringToFloat(string text)
{
    text = checkIfThereIsCommaAndFixItIfIs(text);
    if (checkIfTextHasAnyImpermissibleChars(text) == false)
        return stof(text);
    else
        return -1;
}

bool HelpfulMethods::checkIfTextHasAnyImpermissibleChars(string text)
{
    char numbersAndDot[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    int marker = 0;

    for(int i = 0; i < text.length(); i++)
    {
       for(int j = 0; j < 11; j++)
       {
           if (text[i] == numbersAndDot[j])
           {
               marker++;
           }
       }
    }

    if(marker == text.length())
        return false;
    else
        return true;
}

string HelpfulMethods::checkIfThereIsCommaAndFixItIfIs(string text)
{
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] == ',')
        {
            text[i] = '.';
        }
    }
    return text;
}

string HelpfulMethods::convertFloatToString(float number)
{
    string numberString = to_string(number);

    return numberString.erase(numberString.length() - 4, 4);
}
