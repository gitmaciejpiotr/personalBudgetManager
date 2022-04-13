#ifndef HELPFULMETHODS_H
#define HELPFULMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelpfulMethods
{
public:
    static string convertIntToString(int number);
    static string getLine();
    static string tranformFirstLeterIntoBigOneAndTheRestIntoSmallOnes(string text);
    static string getNumber(string text, int characterPosition);
    static int convertStringToInt(string number);
    static int setInteger();
    static char setCharacter();
};

#endif
