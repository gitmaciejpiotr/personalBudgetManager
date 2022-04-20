#include <iostream>
#include "personalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    char choice;

    while (true)
    {
        if (personalBudget.checkIfUserIsSignedIn() == false)
        {
            choice = personalBudget.selectOptionFromStartMenu();

            switch (choice)
            {
            case '1':
                personalBudget.signUp();
                break;
            case '2':
                personalBudget.signIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such an option" << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.selectOptionFromMenuForSignedInUser();
            bool isItExpensesData = 0;

            switch (choice)
            {
            case '1':
                isItExpensesData = false;
                personalBudget.addNewBudgetData(isItExpensesData);
                break;
            case '2':
                isItExpensesData = true;
                personalBudget.addNewBudgetData(isItExpensesData);
                break;
            case '3':
                personalBudget.showCurrentMonthBalanceSheet();
                break;
            case '4':
                personalBudget.showLatestMonthBalanceSheet();
                break;
            case '5':
                personalBudget.showBalanceSheetForSpecificPeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logOut();
                break;
            }
        }
    }
    return 0;
}
