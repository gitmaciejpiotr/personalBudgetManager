#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "User.h"
#include <windows.h>
#include <winbase.h>
#include "Markup.h"
#include "HelpfulMethods.h"
#include <fstream>

using namespace std;

class FileWithUsers
{
    const string FILE_NAME;

    void initiateBeginningOfXMLFile();

public:
    FileWithUsers(string fileName = "users.xml") : FILE_NAME(fileName)
    {
        initiateBeginningOfXMLFile();
    }
    void addNewUserToFile(User user);
    vector<User> createVectorWithUsersData();
    void changeDataInXMLFile(int signedInUserID, string newPassword);
};


#endif
