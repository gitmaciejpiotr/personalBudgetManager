#include <iostream>
#include "personalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;
    BudgetDataManager budgetDataManager;

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

            switch (choice)
            {
            case '1':
                budgetDataManager.addNewBudgetData();
                break;
            case '2':
                budgetDataManager.addNewBudgetData();
                break;
            case '3':
                budgetDataManager.showCurrentMonthBalanceSheet();
                break;
            case '4':
                budgetDataManager.showLatestMonthBalanceSheet();
                break;
            case '5':
                budgetDataManager.showBalanceSheetForSpecificPeriod();
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
