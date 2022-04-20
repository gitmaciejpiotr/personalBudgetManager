#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "BudgetDataManager.h"
#include "FileWithUsers.h"
#include "HelpfulMethods.h"
#include <vector>

using namespace std;

class UserManager
{
    int signedInUserID;
    vector<User> users;
    FileWithUsers fileWithUsers;

    int getNewUserID();
    void setSignedInUserID();
    bool checkIfLoginIsOccupied(string login);
    User setNewUserData();

public:
    UserManager(int userID) : signedInUserID(userID)
    {
        users = fileWithUsers.createVectorWithUsersData();
    }
    char selectOptionFromMenuForSignedInUser();
    void signUp();
    void addNewUser();
    void changePassword();
    int logOut();
    bool checkIfUserIsSignedIn();
    int signIn();
    //bool isUserSignedIn();
    //int getSignedInUserID();
};


#endif
