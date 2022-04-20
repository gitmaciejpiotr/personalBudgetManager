#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "personalBudget.h"
#include "HelpfulMethods.h"
#include "UserManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BudgetDataManager *budgetDataManager;
    int signedInUserID;

public:
    PersonalBudget(int signedInUserID = 0) : userManager(signedInUserID)
    {
        budgetDataManager = NULL;
    };
    ~PersonalBudget()
    {
        delete budgetDataManager;
        budgetDataManager = NULL;
    };
    void signUp();
    void signIn();
    char selectOptionFromSigningUpMenu();
    char selectOptionFromSigningInMenu();
    char selectOptionFromStartMenu();
    char selectOptionFromMenuForSignedInUser();
    bool checkIfUserIsSignedIn();
    void changePassword();
    void logOut();
    void addNewBudgetData(bool isItExpensesData);
    void showCurrentMonthBalanceSheet();
    void showLatestMonthBalanceSheet();
    void showBalanceSheetForSpecificPeriod();
};


#endif
