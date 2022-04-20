#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "BudgetData.h"
#include <windows.h>
#include <winbase.h>
#include "Markup.h"
#include "HelpfulMethods.h"
#include <fstream>

using namespace std;

class FileWithExpenses
{
    const string FILE_NAME;

    void initiateBeginningOfXMLFile();

public:
    FileWithExpenses(string fileName = "expenses.xml") : FILE_NAME(fileName)
    {
        initiateBeginningOfXMLFile();
    }
    void addNewRecordToFile(BudgetData budgetData, int signedInUserID);
    vector<BudgetData> createVectorWithExpensesData();
};


#endif
