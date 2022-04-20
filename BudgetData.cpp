#include "BudgetData.h"

int BudgetData::getRecordID()
{
    return recordID;
}
int BudgetData::getAmountOfMoney()
{
    return amountOfMoney;
}
int BudgetData::getDate()
{
    return date;
}
string BudgetData::getDescription()
{
    return description;
}
void BudgetData::setRecordID(int newRecordID)
{
    recordID = newRecordID;
}
void BudgetData::setAmountOfMoney(int newAmountOfMoney)
{
    amountOfMoney = newAmountOfMoney;
}
void BudgetData::setDate(int newDate)
{
    date = newDate;
}
void BudgetData::setDescription(string newDescription)
{
    description = newDescription;
}
