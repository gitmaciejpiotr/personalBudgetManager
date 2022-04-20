#include "UserManager.h"

char UserManager::selectOptionFromMenuForSignedInUser()
{
    HelpfulMethods helpfulMethods;
    char choice;

    system("cls");
    cout << " >>> YOUR BUDGET MANAGER <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expese" << endl;
    cout << "3. Show balance sheet of current month" << endl;
    cout << "4. Show balance sheet of previous month" << endl;
    cout << "5. Show balance sheet of certain period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Select an option: ";
    choice = HelpfulMethods::setCharacter();

    return choice;
}

void UserManager::signUp()
{
    User user = setNewUserData();

    users.push_back(user);

    fileWithUsers.addNewUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::setNewUserData()
{
    User user;

    user.setUserID(getNewUserID());

    string login;

    do
    {
        cout << "Podaj login: ";
        login = HelpfulMethods::getLine();
        user.setLogin(login);
    }
    while (checkIfLoginIsOccupied(user.getLogin()) == true);


    string password;
    cout << "Podaj password: ";
    password = HelpfulMethods::getLine();
    user.setPassword(password);

    string name;
    cout << "Podaj name: ";
    name = HelpfulMethods::getLine();
    user.setName(name);

    string surname;
    cout << "Podaj surname: ";
    surname = HelpfulMethods::getLine();
    user.setSurname(surname);

    return user;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = HelpfulMethods::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserID() == signedInUserID)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changeDataInXMLFile(signedInUserID, newPassword);
}

int UserManager::logOut()
{
    signedInUserID = 0;
}

bool UserManager::checkIfUserIsSignedIn()
{
    if (signedInUserID > 0)
        return true;
    else
        return false;
}

void UserManager::setSignedInUserID()
{

}

int UserManager::getNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}

bool UserManager::checkIfLoginIsOccupied(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::signIn()
{
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = HelpfulMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj password. Pozostalo prob: " << numberOfAttempts << ": ";
                password = HelpfulMethods::getLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    signedInUserID = itr -> getUserID();
                    return signedInUserID;
                }
            }
            cout << "Wprowadzono 3 razy bledne password." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

/*bool UserManager::isUserSignedIn()
{
    if (signedInUserID > 0)
        return true;
    else
        return false;
}

int UserManager::getSignedInUserID()
{
    return signedInUserID;
}*/

