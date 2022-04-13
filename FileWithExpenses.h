#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "BudgetData.h"

using namespace std;

class FileWithExpenses
{
    const string FILE_NAME;

public:
    FileWithExpenses(string fileName = "expenses.xml") : FILE_NAME(fileName){};
    void addNewRecordToFile(BudgetData budgetData);
    vector<BudgetData> createVectorWithExpensesData();
};


#endif
