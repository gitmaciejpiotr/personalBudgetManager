#include "FileWithExpenses.h"

void FileWithExpenses::addNewRecordToFile(BudgetData budgetData, int signedInUserID)
{
    CMarkup xml;
    xml.Load(FILE_NAME);
    string childElemName = "expense";


    xml.FindElem("expenses");


    xml.AddChildElem(childElemName);
    xml.IntoElem();
    xml.AddChildElem("expenseId", HelpfulMethods::convertIntToString(budgetData.getRecordID()));
    xml.AddChildElem("userId", signedInUserID);
    xml.AddChildElem("date", HelpfulMethods::convertIntDateToStringDate(budgetData.getDate()));
    xml.AddChildElem("item", budgetData.getDescription());
    xml.AddChildElem("amount", HelpfulMethods::convertFloatToString(budgetData.getAmountOfMoney()));
    xml.OutOfElem();

    xml.Save(FILE_NAME);
}

void FileWithExpenses::initiateBeginningOfXMLFile()
{
    fstream file;

    file.open(FILE_NAME.c_str());

    if (!file.good())
    {
        CMarkup xml;
        xml.AddElem("expenses");
        xml.Save(FILE_NAME);
    }
    file.close();
}

vector<BudgetData> FileWithExpenses::createVectorWithExpensesData()
{
    fstream file;
    file.open(FILE_NAME.c_str());

    if (file.good())
    {
        BudgetData budgetData;
        vector<BudgetData> budgetDataInVector;

        CMarkup xml;
        xml.Load(FILE_NAME);

        string childElemName = "expense";

        while(xml.FindChildElem(childElemName))
        {
            xml.IntoElem();
            xml.FindChildElem("expenseId");
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
