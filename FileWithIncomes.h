#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include "BudgetData.h"
#include "Markup.h"
#include "HelpfulMethods.h"
#include <fstream>

using namespace std;

class FileWithIncomes
{
    const string FILE_NAME;

    void initiateBeginningOfXMLFile();

public:
    FileWithIncomes(string fileName = "incomes.xml") : FILE_NAME(fileName)
    {
        initiateBeginningOfXMLFile();
    };
    void addNewRecordToFile(BudgetData budgetData, int signedInUserID);
    vector<BudgetData> createVectorWithIncomeData();
};


#endif
