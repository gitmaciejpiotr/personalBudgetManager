#include "FileWithUsers.h"

void FileWithUsers::addNewUserToFile(User user)
{
    CMarkup xml;
    xml.Load(FILE_NAME);
    string childElemName = "user";

    xml.FindElem("users");

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

    if (file.good())
    {
        User user;
        vector<User> users;

        CMarkup xml;
        xml.Load(FILE_NAME);

        int number = 1;
        string childElemName = "user";

        while(xml.FindChildElem(childElemName))
        {
            xml.IntoElem();
            xml.FindChildElem("userid");
            user.setUserID(HelpfulMethods::convertStringToInt(xml.GetChildData()));
            xml.FindChildElem( "login" );
            user.setLogin(xml.GetChildData());
            xml.FindChildElem( "password" );
            user.setPassword(xml.GetChildData());
            xml.FindChildElem( "name" );
            user.setName(xml.GetChildData());
            xml.FindChildElem( "surname" );
            user.setSurname(xml.GetChildData());
            xml.OutOfElem();

            users.push_back(user);
        }

        return users;
    }
    file.close();
}

void FileWithUsers::initiateBeginningOfXMLFile()
{
    fstream file;

    file.open(FILE_NAME.c_str());

    if (!file.good())
    {
        CMarkup xml;
        xml.AddElem("users");
        xml.Save(FILE_NAME);
    }
    file.close();
}

void FileWithUsers::changePasswordInXMLFile(int signedInUserID, string newPassword)
{
    CMarkup xml;
    xml.Load(FILE_NAME);

    string childElemName = "user";

    xml.FindElem("users");
    xml.IntoElem();
    while (xml.FindElem(childElemName))
    {
        xml.FindChildElem("userid");

        if(atoi(MCD_2PCSZ(xml.GetChildData())) == signedInUserID)
        {
            xml.FindChildElem("password");
            xml.SetChildData(newPassword);
            break;
        }
    }
    xml.Save(FILE_NAME);
}
