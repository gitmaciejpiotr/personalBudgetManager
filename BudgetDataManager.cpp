#include "BudgetDataManager.h"

void BudgetDataManager::showCurrentMonthBalanceSheet()
{

}

void BudgetDataManager::showLatestMonthBalanceSheet()
{

}

void BudgetDataManager::showBalanceSheetForSpecificPeriod()
{

}

void BudgetDataManager::addNewBudgetData(bool isItExpensesData)
{
    bool isItWithCurrentDate = false;                                   //          PRECISE IT DUDE

    BudgetData budgetData = setNewBudgetData(isItExpensesData, isItWithCurrentDate);

    if (isItExpensesData == true)
    {
        expensesData.push_back(budgetData);
        fileWithExpenses.addNewRecordToFile(budgetData, SIGNED_IN_USER_ID);
    }
    else
    {
        incomesData.push_back(budgetData);
        fileWithIncomes.addNewRecordToFile(budgetData, SIGNED_IN_USER_ID);
    }
}

BudgetData BudgetDataManager::setNewBudgetData(bool isItExpensesData, bool isItWithCurrentDate)
{
    BudgetData budgetData;

    budgetData.setRecordID(getNewRecordID(isItExpensesData));

    int amoutOfMoney;
    cout << "Podaj amount of money: ";
    amoutOfMoney = HelpfulMethods::convertStringToInt(HelpfulMethods::getLine());
    budgetData.setAmountOfMoney(amoutOfMoney);

    if (isItWithCurrentDate == false)
    {
        int date;
        cout << "Podaj date: ";
        date = HelpfulMethods::convertStringToInt(HelpfulMethods::getLine());
        budgetData.setDate(date);
    }
    else
    {
        //set current date somehow
    }


    string description;
    cout << "Podaj description: ";
    description = HelpfulMethods::getLine();
    budgetData.setDescription(description);

    return budgetData;
}

int BudgetDataManager::getNewRecordID(bool isItExpensesData)
{
    if(isItExpensesData == true)
    {
        if(expensesData.empty() == true)
        {
            cout << SIGNED_IN_USER_ID << endl;
            system("pause");

            return 1;
        }

        else
            return expensesData.back().getRecordID() + 1;
    }
    else
    {
        if(incomesData.empty() == true)
            return 1;
        else
            return incomesData.back().getRecordID() + 1;
    }

}
