#ifndef BUDGETDATAMANAGER_H
#define BUDGETDATAMANAGER_H

#include <iostream>
#include "BudgetData.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include <vector>
#include <iomanip>
#include <cmath>

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
    bool askAboutDateInRecord();
    bool checkIfDateFormatIsCorrect(string dateString);
    bool checkIfAfterDotAreMaxTwoChars(float amountOfMoney);
    bool checkIfDatesAreInRigthOrder(string dateString1, string dateString2);
    bool dateTest1(string dateString);
    bool dateTest2(string dateString);
    bool dateTest3(string dateString);
    bool dateTest4(string dateString);
    bool dateTest5(string dateString);
    bool dateTest6(string dateString, bool test5);
    bool dateTest7(string dateString);


public:

    BudgetDataManager(int userID = 0) : SIGNED_IN_USER_ID(userID)
    {
        incomesData = fileWithIncomes.createVectorWithIncomeData();
        expensesData = fileWithExpenses.createVectorWithExpensesData();
    };
    void showBalanceSheetOfCertainPeriod(int balanceSheetOption);
    void addNewBudgetData(bool isItExpensesData);
    vector<BudgetData> sortBudgetDataByDate(vector<BudgetData> budgetDataInVector);

};


#endif
