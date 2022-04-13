#include "personalBudget.h"

void PersonalBudget::signUp()
{
    userManager.signUp();
}

int PersonalBudget::signIn()
{
    signedInUserID = userManager.signIn();
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
    cout << "Chosen option: ";
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
    userManager.logOut();
}

