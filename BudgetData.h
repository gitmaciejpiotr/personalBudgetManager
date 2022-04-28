#ifndef BUDGETDATA_H
#define BUDGETDATA_H

#include <iostream>
#include "BudgetData.h"

using namespace std;

class BudgetData
{
    int recordID;
    int userID;
    float amountOfMoney;
    int date;
    string description;

public:
    int getRecordID();
    float getAmountOfMoney();
    int getDate();
    string getDescription();
    int getUserID();
    void setRecordID(int newRecordID);
    void setAmountOfMoney(float newAmountOfMoney);
    void setDate(int newDate);
    void setDescription(string newDescription);
    void setUserID(int newID);

};


#endif
