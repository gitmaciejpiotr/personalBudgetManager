#include "FileWithUsers.h"

void FileWithUsers::addNewUserToFile(User user)
{
    CMarkup xml;
    xml.Load(FILE_NAME);

    xml.FindElem("users");

    string childElemName = "user" + HelpfulMethods::convertIntToString(user.getUserID() - 1);
    if(user.getUserID() > 1)
    {
        xml.FindChildElem(childElemName);
    }

    childElemName = "user" + HelpfulMethods::convertIntToString(user.getUserID());

    xml.AddChildElem(childElemName);
    xml.IntoElem();
    xml.AddChildElem("userid", HelpfulMethods::convertIntToString(user.getUserID()));
    xml.AddChildElem("login", user.getLogin());
    xml.AddChildElem("password", user.getPassword());
    xml.AddChildElem("name", user.getName());
    xml.AddChildElem("surname", user.getSurname());
    xml.OutOfElem();

    xml.Save(FILE_NAME);
}

vector<User> FileWithUsers::createVectorWithUsersData()
{
    fstream file;
    file.open(FILE_NAME.c_str());

    if (file.good() == true)
    {
        User user;
        vector<User> users;

        CMarkup xml;
        xml.Load(FILE_NAME);

        int number = 1;
        string childElemName = "user" + HelpfulMethods::convertIntToString(number);

        while(xml.FindChildElem(childElemName) == true)
        {
            xml.FindChildElem(childElemName);
            xml.IntoElem();
            xml.FindChildElem("userid");
            user.setUserID(HelpfulMethods::convertStringToInt(xml.GetChildData()));
            // cout << user.getUserID() << endl;
            xml.FindChildElem( "login" );
            user.setLogin(xml.GetChildData());
            //cout << user.getLogin() << endl;
            xml.FindChildElem( "password" );
            user.setPassword(xml.GetChildData());
            //cout << user.getPassword() << endl;
            xml.FindChildElem( "name" );
            user.setName(xml.GetChildData());
            // cout << user.getName() << endl;
            xml.FindChildElem( "surname" );
            user.setSurname(xml.GetChildData());
            xml.OutOfElem();

            users.push_back(user);

            number++;
            childElemName = "user" + HelpfulMethods::convertIntToString(number);
        }

        return users;
    }
    file.close();
}

void FileWithUsers::initiateBeginningOfXMLFile()
{
    fstream file;

    file.open(FILE_NAME.c_str());

    if (file.good() == false)
    {
        CMarkup xml;
        xml.AddElem("users");
        xml.Save(FILE_NAME);
    }
    file.close();
}

void FileWithUsers::changeDataInXMLFile(int signedInUserID, string newPassword)
{
    CMarkup xml;
    xml.Load(FILE_NAME);

    string childElemName = "user" + HelpfulMethods::convertIntToString(signedInUserID);

    xml.ResetChildPos();
    xml.FindChildElem(childElemName);
    xml.IntoElem();
    xml.FindChildElem("password");
    xml.RemoveChildElem();
    xml.OutOfElem();
}
