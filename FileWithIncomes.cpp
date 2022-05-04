#include "FileWithIncomes.h"

void FileWithIncomes::addNewRecordToFile(BudgetData budgetData, int signedInUserID)
{
    CMarkup xml;
    xml.Load(FILE_NAME);
    string childElemName = "income";

    xml.FindElem("incomes");

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

    if (file.good())
    {
        BudgetData budgetData;
        vector<BudgetData> budgetDataInVector;

        CMarkup xml;
        xml.Load(FILE_NAME);

        string childElemName = "income";

        while(xml.FindChildElem(childElemName))
        {
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
        }

        return budgetDataInVector;
    }
    file.close();
}

void FileWithIncomes::initiateBeginningOfXMLFile()
{
    fstream file;

    file.open(FILE_NAME.c_str());

    if (!file.good())
    {
        CMarkup xml;
        xml.AddElem("incomes");
        xml.Save(FILE_NAME);
    }
    file.close();
}
