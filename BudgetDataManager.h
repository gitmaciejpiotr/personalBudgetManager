#ifndef BUDGETDATAMANAGER_H
#define BUDGETDATAMANAGER_H

#include <iostream>
#include "BudgetData.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include <vector>

using namespace std;

class BudgetDataManager
{
    int signedInUserID;
    vector<BudgetData> incomesData;
    vector<BudgetData> expensesData;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

public:
    BudgetDataManager()
    {
        ;
    }
    void showCurrentMonthBalanceSheet();
    void showLatestMonthBalanceSheet();
    void showBalanceSheetForSpecificPeriod();
    void addNewBudgetData();

};


#endif
