#include <iostream>
#include "personalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    char choice;

    while (true)
    {
        if (!personalBudget.checkIfUserIsSignedIn())
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
                cout << endl << "Nie ma takiej opcji w menu" << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.selectOptionFromMenuForSignedInUser();
            bool isItExpensesData = 0;
            int balanceSheetOption = 0;

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
                balanceSheetOption = 1;
                personalBudget.showBalanceSheetOfCertainPeriod(balanceSheetOption);
                break;
            case '4':
                balanceSheetOption = 2;
                personalBudget.showBalanceSheetOfCertainPeriod(balanceSheetOption);
                break;
            case '5':
                balanceSheetOption = 3;
                personalBudget.showBalanceSheetOfCertainPeriod(balanceSheetOption);
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logOut();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu" << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
