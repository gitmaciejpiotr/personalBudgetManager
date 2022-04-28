#include "personalBudget.h"

void PersonalBudget::signUp()
{
    userManager.signUp();
}

void PersonalBudget::signIn()
{
    signedInUserID = userManager.signIn();

    if (signedInUserID > 0)
    {
        budgetDataManager = new BudgetDataManager(signedInUserID);
    }
}

char PersonalBudget::selectOptionFromSigningInMenu()
{

}

char PersonalBudget::selectOptionFromSigningUpMenu()
{

}

char PersonalBudget::selectOptionFromStartMenu()
{
    HelpfulMethods helpfulMethods;
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Wybierz opcje: ";
    choice = helpfulMethods.setCharacter();

    return choice;
}

char PersonalBudget::selectOptionFromMenuForSignedInUser()
{
    userManager.selectOptionFromMenuForSignedInUser();
}

bool PersonalBudget::checkIfUserIsSignedIn()
{
    userManager.checkIfUserIsSignedIn();
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::logOut()
{
    signedInUserID = userManager.logOut();
}

void PersonalBudget::addNewBudgetData(bool isItExpensesData)
{
    budgetDataManager->addNewBudgetData(isItExpensesData);
}

void PersonalBudget::showBalanceSheetOfCertainPeriod(int balanceSheetOption)
{
    budgetDataManager->showBalanceSheetOfCertainPeriod(balanceSheetOption);
}


