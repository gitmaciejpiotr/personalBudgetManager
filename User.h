#ifndef USER_H
#define USER_H

#include <iostream>
#include "User.h"

using namespace std;

class User
{
    string name;
    string surname;
    string login;
    string password;
    int userID;

public:
    string getName();
    string getSurname();
    string getPassword();
    string getLogin();
    int getUserID();
    void setName(string newName);
    void setSurname(string newSurname);
    void setPassword(string newPassword);
    void setLogin(string newLogin);
    void setUserID(int newID);
};


#endif
