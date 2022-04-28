#include "BudgetData.h"

int BudgetData::getRecordID()
{
    return recordID;
}
float BudgetData::getAmountOfMoney()
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
int BudgetData::getUserID()
{
    return userID;
}
void BudgetData::setRecordID(int newRecordID)
{
    recordID = newRecordID;
}
void BudgetData::setAmountOfMoney(float newAmountOfMoney)
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
void BudgetData::setUserID(int newID)
{
    userID = newID;
}
