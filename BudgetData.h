#ifndef BUDGETDATA_H
#define BUDGETDATA_H

#include <iostream>
#include "BudgetData.h"

using namespace std;

class BudgetData
{
    int recordID;
    int amountOfMoney;
    int date;
    string description;

public:
    int getRecordID();
    int getAmountOfMoney();
    int getDate();
    string getDescription();
    void setRecordID(int newRecordID);
    void setAmountOfMoney(int newAmountOfMoney);
    void setDate(int newDate);
    void setDescription(string newDescription);

};


#endif
