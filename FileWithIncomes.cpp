#include "FileWithIncomes.h"

void FileWithIncomes::addNewRecordToFile(BudgetData budgetData, int signedInUserID)
{
    CMarkup xml;
    xml.Load(FILE_NAME);
    string childElemName = "income" + HelpfulMethods::convertIntToString(budgetData.getRecordID() - 1);


    xml.FindElem("incomes");

    if(budgetData.getRecordID() > 1)
    {
        xml.FindChildElem(childElemName);
    }

    childElemName = "income" + HelpfulMethods::convertIntToString(budgetData.getRecordID());

    xml.AddChildElem(childElemName);
    xml.IntoElem();
    xml.AddChildElem("incomeId", HelpfulMethods::convertIntToString(budgetData.getRecordID()));
    xml.AddChildElem("userId", signedInUserID);
    xml.AddChildElem("date", HelpfulMethods::convertIntDateToStringDate(budgetData.getDate()));
    xml.AddChildElem("item", budgetData.getDescription());
    xml.AddChildElem("amount", HelpfulMethods::convertFloatToString(budgetData.getAmountOfMoney()));
    xml.OutOfElem();

    xml.Save(FILE_NAME);
}

vector<BudgetData> FileWithIncomes::createVectorWithIncomeData()
{
    fstream file;
    file.open(FILE_NAME.c_str());

    if (file.good() == true)
    {
        BudgetData budgetData;
        vector<BudgetData> budgetDataInVector;

        CMarkup xml;
        xml.Load(FILE_NAME);

        int number = 1;
        string childElemName = "income" + HelpfulMethods::convertIntToString(number);

        while(xml.FindChildElem(childElemName) == true)
        {
            xml.FindChildElem(childElemName);
            xml.IntoElem();
            xml.FindChildElem("incomeId");
            budgetData.setRecordID(HelpfulMethods::convertStringToInt(xml.GetChildData()));
            xml.FindChildElem("userId");
            budgetData.setUserID(HelpfulMethods::convertStringToInt(xml.GetChildData()));
            xml.FindChildElem( "date" );
            budgetData.setDate(HelpfulMethods::convertStringDateToIntDate(xml.GetChildData()));
            xml.FindChildElem( "item" );
            budgetData.setDescription(xml.GetChildData());
            xml.FindChildElem( "amount" );
            budgetData.setAmountOfMoney(HelpfulMethods::convertStringToFloat(xml.GetChildData()));
            xml.OutOfElem();

            budgetDataInVector.push_back(budgetData);

            number++;
            childElemName = "income" + HelpfulMethods::convertIntToString(number);
        }

        return budgetDataInVector;
    }
    file.close();
}

void FileWithIncomes::initiateBeginningOfXMLFile()
{
    fstream file;

    file.open(FILE_NAME.c_str());

    if (file.good() == false)
    {
        CMarkup xml;
        xml.AddElem("incomes");
        xml.Save(FILE_NAME);
    }
    file.close();
}
