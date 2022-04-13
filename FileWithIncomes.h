#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include "BudgetData.h"

using namespace std;

class FileWithIncomes
{
    const string FILE_NAME;

public:
    FileWithIncomes(string fileName = "incomes.xml") : FILE_NAME(fileName){};
    void addNewRecordToFile(BudgetData budgetData);
    vector<BudgetData> createVectorWithIncomeData();
};


#endif
