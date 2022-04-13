#include "User.h"

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}

string User::getPassword()
{
    return password;
}

string User::getLogin()
{
    return login;
}

int User::getUserID()
{
    return userID;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setSurname(string newSurname)
{
    surname = newSurname;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}
void User::setLogin(string newLogin)
{
    login = newLogin;
}

void User::setUserID(int newID)
{
    if (newID >= 0)
        userID = newID;
}
