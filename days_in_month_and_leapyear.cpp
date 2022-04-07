#include <iostream>
#include <windows.h>
#include <winbase.h>

using namespace std;
int main()
{
    int month , days, year;
    bool leapyear;

    cout << "Miesiac: ";
    cin >> month;

    cout << "Rok: ";
    cin >> year;
    cout << endl;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;

    else if (month == 02)
    {
        leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapyear == 0)
            days = 28;
        else
            days = 29;
    }

    else
        days = 31;

    cout << "Dni w miesiacu: " << days << endl;
    if (leapyear == 1)
    {
        cout << "Rok przestepny" << endl;
    }
    else
    {
        cout << "Rok nieprzestepny" << endl;
    }

    return 0;
}

