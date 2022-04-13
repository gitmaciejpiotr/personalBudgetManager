#ifndef BUDGETDATA_H
#define BUDGETDATA_H

#include <iostream>
#include "BudgetData.h"

using namespace std;

class BudgetData
{
    int recordID;
    int amountOfMoney;
    string date;
    string description;

public:
    int getRecordID();
    int getAmountOfMoney();
    string getDate();
    string getDescription();
    void setRecordID();
    void setAmountOfMoney();
    void setDate();
    void setDescription();

};


#endif
