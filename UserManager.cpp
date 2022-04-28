#include "UserManager.h"

char UserManager::selectOptionFromMenuForSignedInUser()
{
    HelpfulMethods helpfulMethods;
    char choice;

    system("cls");
    cout << " >>> TWOJ BUDZET OSOBISTY <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Wybierz opcje: ";
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
    cout << "Podaj haslo: ";
    password = HelpfulMethods::getLine();
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    name = HelpfulMethods::getLine();
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
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
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = HelpfulMethods::getLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    signedInUserID = itr -> getUserID();
                    return signedInUserID;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
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

