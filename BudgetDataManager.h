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
    const int SIGNED_IN_USER_ID;

    vector<BudgetData> incomesData;
    vector<BudgetData> expensesData;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    BudgetData setNewBudgetData(bool isItExpensesData, bool isItWithCurrentDate);
    int getNewRecordID(bool isItExpensesData);

public:

    BudgetDataManager(int userID = 0) : SIGNED_IN_USER_ID(userID)
    {
        incomesData = fileWithIncomes.createVectorWithIncomeData();
        expensesData = fileWithExpenses.createVectorWithExpensesData();
    };
    void showCurrentMonthBalanceSheet();
    void showLatestMonthBalanceSheet();
    void showBalanceSheetForSpecificPeriod();
    void addNewBudgetData(bool isItExpensesData);

};


#endif
