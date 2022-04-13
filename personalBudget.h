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
    int signedInUserID;

public:
    PersonalBudget(int signedInUserID = 0) : userManager(signedInUserID){};
    void signUp();
    int signIn();
    char selectOptionFromSigningUpMenu();
    char selectOptionFromSigningInMenu();
    char selectOptionFromStartMenu();
    char selectOptionFromMenuForSignedInUser();
    bool checkIfUserIsSignedIn();
    void changePassword();
    void logOut();
};


#endif
