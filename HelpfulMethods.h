#ifndef HELPFULMETHODS_H
#define HELPFULMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

class HelpfulMethods
{
    static string checkIfThereIsCommaAndFixItIfIs(string text);
    static bool checkIfTextHasAnyImpermissibleChars(string text);

public:
    static string convertIntToString(int number);
    static string getLine();
    static string tranformFirstLeterIntoBigOneAndTheRestIntoSmallOnes(string text);
    static string getNumber(string text, int characterPosition);
    static int convertStringToInt(string number);
    static int setInteger();
    static char setCharacter();
    static int convertStringDateToIntDate(string dateString);
    static string convertIntDateToStringDate(int date);
    static float convertStringToFloat(string text);
    static string convertFloatToString(float number);
    static int getDayIntFromStringDate(string dateString);
    static int getMonthIntFromStringDate(string dateString);
    static int getYearIntFromStringDate(string dateString);
};

#endif
