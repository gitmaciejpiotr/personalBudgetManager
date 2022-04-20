#include "FileWithExpenses.h"

void FileWithExpenses::addNewRecordToFile(BudgetData budgetData, int signedInUserID)
{
    CMarkup xml;
    xml.Load(FILE_NAME);
    string childElemName = "expense" + HelpfulMethods::convertIntToString(budgetData.getRecordID() - 1);


    xml.FindElem("expenses");

    if(budgetData.getRecordID() > 1)
    {
        xml.FindChildElem(childElemName);
    }

    childElemName = "expense" + HelpfulMethods::convertIntToString(budgetData.getRecordID());

    xml.AddChildElem(childElemName);
    xml.IntoElem();
    xml.AddChildElem("expenseId", HelpfulMethods::convertIntToString(budgetData.getRecordID()));
    xml.AddChildElem("userId", signedInUserID);
    xml.AddChildElem("date", budgetData.getDate());
    xml.AddChildElem("item", budgetData.getDescription());
    xml.AddChildElem("amount", budgetData.getAmountOfMoney());
    xml.OutOfElem();

    xml.Save(FILE_NAME);
}

void FileWithExpenses::initiateBeginningOfXMLFile()
{
    fstream file;

    file.open(FILE_NAME.c_str());

    if (file.good() == false)
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

    if (file.good() == true)
    {
        BudgetData budgetData;
        vector<BudgetData> budgetDataInVector;

        CMarkup xml;
        xml.Load(FILE_NAME);

        int number = 1;
        string childElemName = "expense" + HelpfulMethods::convertIntToString(number);

        while(xml.FindChildElem(childElemName) == true)
        {
            xml.FindChildElem(childElemName);
            xml.IntoElem();
            xml.FindChildElem("expenseId");
            budgetData.setRecordID(HelpfulMethods::convertStringToInt(xml.GetChildData()));
            xml.FindChildElem( "date" );
            budgetData.setDate(HelpfulMethods::convertStringToInt(xml.GetChildData()));
            xml.FindChildElem( "item" );
            budgetData.setDescription(xml.GetChildData());
            xml.FindChildElem( "amount" );
            budgetData.setAmountOfMoney(HelpfulMethods::convertStringToInt(xml.GetChildData()));
            xml.OutOfElem();

            budgetDataInVector.push_back(budgetData);

            number++;
            childElemName = "expense" + HelpfulMethods::convertIntToString(number);
        }

        return budgetDataInVector;
    }
    file.close();
}
