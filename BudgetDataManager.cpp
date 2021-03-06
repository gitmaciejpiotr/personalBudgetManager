#include "BudgetDataManager.h"

void BudgetDataManager::showBalanceSheetOfCertainPeriod(int balanceSheetOption)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    vector<BudgetData> selectedIncomesData;
    vector<BudgetData> selectedExpensesData;
    int firstDayOfCertainPeriod, lastDayOfCertainPeriod;

    if(balanceSheetOption == 1)
    {
        firstDayOfCertainPeriod = st.wYear*10000 + st.wMonth*100 + 1;
        lastDayOfCertainPeriod = st.wYear*10000 + st.wMonth*100 + st.wDay;
    }

    else if(balanceSheetOption == 2)
    {
        firstDayOfCertainPeriod = st.wYear*10000 + (st.wMonth - 1)*100 + 1;
        lastDayOfCertainPeriod = st.wYear*10000 + (st.wMonth - 1)*100 + 31;
    }

    else if(balanceSheetOption == 3)
    {
        string dateString1, dateString2;
        cout << endl << "Date nalezy wpisac w nastepujacym formacie: rrrr-mm-dd" << endl;
        cout << "Podaj date poczatkowa: ";
        dateString1 = HelpfulMethods::getLine();

        while(!checkIfDateFormatIsCorrect(dateString1))
        {
            cout << endl << "Niepoprawny format lub wartosc powyzszej daty." << endl;
            cout << "Wpisz ponownie: ";

            dateString1 = HelpfulMethods::getLine();
        }

        cout << "Podaj date koncowa: ";
        dateString2 = HelpfulMethods::getLine();

        while(!checkIfDateFormatIsCorrect(dateString2))
        {
            cout << endl << "Niepoprawny format lub wartosc powyzszej daty." << endl;
            cout << "Wpisz ponownie: ";

            dateString2 = HelpfulMethods::getLine();
        }

        while(!checkIfDatesAreInRigthOrder(dateString1, dateString2))
        {
            cout << endl << "Niepoprawna kolejnosc dat." << endl;
            cout << "Wpisz ponownie pierwsza date: ";

            dateString1 = HelpfulMethods::getLine();

            cout << "Wpisz ponownie druga date: ";

            dateString2 = HelpfulMethods::getLine();
        }

        firstDayOfCertainPeriod = HelpfulMethods::convertStringDateToIntDate(dateString1);
        lastDayOfCertainPeriod = HelpfulMethods::convertStringDateToIntDate(dateString2);
    }


    for (int i = 0; i < incomesData.size(); i++)
    {
        if(incomesData[i].getDate() >= firstDayOfCertainPeriod && incomesData[i].getDate() <= lastDayOfCertainPeriod && incomesData[i].getUserID() == SIGNED_IN_USER_ID)
        {
            selectedIncomesData.push_back(incomesData[i]);
        }
    }

    for (int i = 0; i < expensesData.size(); i++)
    {
        if(expensesData[i].getDate() >= firstDayOfCertainPeriod && expensesData[i].getDate() <= lastDayOfCertainPeriod && expensesData[i].getUserID() == SIGNED_IN_USER_ID)
        {
            selectedExpensesData.push_back(expensesData[i]);
        }
    }

    vector<BudgetData> sortedIncomesByDate = sortBudgetDataByDate(selectedIncomesData);
    vector<BudgetData> sortedExpensesByDate = sortBudgetDataByDate(selectedExpensesData);
    float sumOfIncomes = 0, sumOfExpences = 0;

    cout << "Przychody: " << endl;

    for(int i = 0; i < sortedIncomesByDate.size(); i++)
    {
        sumOfIncomes += sortedIncomesByDate[i].getAmountOfMoney();
        cout << HelpfulMethods::convertIntDateToStringDate(sortedIncomesByDate[i].getDate()) << " | " << sortedIncomesByDate[i].getDescription() << " | " << HelpfulMethods::convertFloatToString(sortedIncomesByDate[i].getAmountOfMoney()) << " zl" << endl;
    }

    if(sortedIncomesByDate.size() == 0)
    {
        cout << "Brak przychodow." << endl;
    }

    cout << "Wydatki: " << endl;

    for(int i = 0; i < sortedExpensesByDate.size(); i++)
    {
        sumOfExpences += sortedExpensesByDate[i].getAmountOfMoney();
        cout << HelpfulMethods::convertIntDateToStringDate(sortedExpensesByDate[i].getDate()) << " | " << sortedExpensesByDate[i].getDescription() << " | " << HelpfulMethods::convertFloatToString(sortedExpensesByDate[i].getAmountOfMoney()) << " zl" << endl;
    }

    if(sortedExpensesByDate.size() == 0)
    {
        cout << "Brak wydatkow." << endl;
    }

    cout << endl << "Suma przychodow: " << HelpfulMethods::convertFloatToString(sumOfIncomes) << " zl" << endl;
    cout << "Suma wydatkow: " << HelpfulMethods::convertFloatToString(sumOfExpences) << " zl" << endl;
    if (balanceSheetOption == 1)
    {
        cout << endl << "Bilans z biezacego miesiaca: " << HelpfulMethods::convertFloatToString(sumOfIncomes - sumOfExpences) << " zl" << endl;
    }
    else if(balanceSheetOption == 2)
    {
        cout << endl << "Bilans z poprzedniego miesiaca: " << HelpfulMethods::convertFloatToString(sumOfIncomes - sumOfExpences) << " zl" << endl;
    }
    else if(balanceSheetOption == 3)
    {
        cout << endl << "Bilans z wybranego okresu: " << HelpfulMethods::convertFloatToString(sumOfIncomes - sumOfExpences) << " zl" << endl << endl;
    }

    system("pause");
}

bool BudgetDataManager::checkIfDatesAreInRigthOrder(string dateString1, string dateString2)
{
    int firstDayOfCertainPeriod = HelpfulMethods::convertStringDateToIntDate(dateString1);
    int lastDayOfCertainPeriod = HelpfulMethods::convertStringDateToIntDate(dateString2);

    return(firstDayOfCertainPeriod < lastDayOfCertainPeriod);
}

void BudgetDataManager::addNewBudgetData(bool isItExpensesData)
{
    bool isItWithCurrentDate = askAboutDateInRecord();

    BudgetData budgetData = setNewBudgetData(isItExpensesData, isItWithCurrentDate);

    if (isItExpensesData)
    {
        expensesData.push_back(budgetData);
        fileWithExpenses.addNewRecordToFile(budgetData, SIGNED_IN_USER_ID);
    }
    else
    {
        incomesData.push_back(budgetData);
        fileWithIncomes.addNewRecordToFile(budgetData, SIGNED_IN_USER_ID);
    }

    cout << endl << "Pomyslnie dodano nowy zapis." << endl;
    system("pause");
}

BudgetData BudgetDataManager::setNewBudgetData(bool isItExpensesData, bool isItWithCurrentDate)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    BudgetData budgetData;

    budgetData.setRecordID(getNewRecordID(isItExpensesData));
    budgetData.setUserID(SIGNED_IN_USER_ID);

    if (!isItWithCurrentDate)
    {
        int dateInt;
        string dateString;
        cout << endl << "Date nalezy wpisac w nastepujacym formacie: rrrr-mm-dd" << endl;
        cout << "Podaj date: ";
        dateString = HelpfulMethods::getLine();

        while(!checkIfDateFormatIsCorrect(dateString))
        {
            cout << endl << "Niepoprawny format lub wartosc daty." << endl;
            cout << "Wpisz date ponownie: ";

            dateString = HelpfulMethods::getLine();
        }

        dateInt = HelpfulMethods::convertStringDateToIntDate(dateString);

        budgetData.setDate(dateInt);
    }
    else
    {
        int yearInt = st.wYear * 10000;
        int monthInt = st.wMonth * 100;
        int dayInt = st.wDay;

        int dateInt = yearInt + monthInt + dayInt;

        budgetData.setDate(dateInt);
    }

    float amountOfMoney;
    cout << "Podaj sume: ";
    amountOfMoney = HelpfulMethods::convertStringToFloat(HelpfulMethods::getLine());
    while(!checkIfAfterDotAreMaxTwoChars(amountOfMoney))
    {
        cout << "Wpisano zbyt wiele cyfr po przecinku." << endl;
        cout << "Wpisz sume ponownie: ";
        amountOfMoney = HelpfulMethods::convertStringToFloat(HelpfulMethods::getLine());
    }

    while(amountOfMoney == -1)
    {
        cout << "Wpisano niedozwolony znak." << endl;
        cout << "Wpisz sume ponownie: ";
        amountOfMoney = HelpfulMethods::convertStringToFloat(HelpfulMethods::getLine());
    }
    budgetData.setAmountOfMoney(amountOfMoney);


    string description;
    cout << "Podaj opis: ";
    description = HelpfulMethods::getLine();
    budgetData.setDescription(description);

    return budgetData;
}

bool BudgetDataManager::checkIfAfterDotAreMaxTwoChars(float amountOfMoney)
{
    string amountOfMoneyString = HelpfulMethods::convertFloatToString(amountOfMoney);
    int marker = 0, length = amountOfMoneyString.length();

    for (int i = 0; i < length; i++)
    {
        if(amountOfMoneyString[i] == '.')
        {
            marker = i;
        }
    }

    return (marker == length - 2 || marker == length - 3 || marker == 0);
}

int BudgetDataManager::getNewRecordID(bool isItExpensesData)
{
    if(isItExpensesData)
    {
        if(expensesData.empty())
            return 1;
        else
            return expensesData.back().getRecordID() + 1;
    }
    else
    {
        if(incomesData.empty())
            return 1;
        else
            return incomesData.back().getRecordID() + 1;
    }
}

bool BudgetDataManager::askAboutDateInRecord()
{
    string yesOrNo;

    cout << "Czy chcesz zapisac dane z dziejsza data?" << endl;
    cout << endl << "Nacisnij 't', jesli tak lub 'n', jesli nie" << endl;

    while(1)
    {
        yesOrNo = HelpfulMethods::getLine();

        if(yesOrNo == "t")
        {
            return true;
        }
        else if(yesOrNo == "n")
        {
            return false;
        }
        else
        {
            cout << "Wpisano nieodpowiedni znak." << endl << endl;
            cout << "Wybierz ponownie: ";
        }
    }
}

bool BudgetDataManager::checkIfDateFormatIsCorrect(string dateString)
{
    bool test1 = dateTest1(dateString);
    bool test2 = dateTest2(dateString);
    bool test3 = dateTest3(dateString);
    bool test4 = dateTest4(dateString);
    bool test5 = dateTest5(dateString);
    bool test6 = dateTest6(dateString, test5);
    bool test7 = dateTest7(dateString);

    return (test1 && test2 && test3 && test4 && test5 && test6 && test7);
}

bool BudgetDataManager::dateTest1(string dateString)
{
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int correctNumChars = 0;

    for (int i = 0; i < 10; i++)
    {
        int numChar = 0;

        for (int j = 0; j < 10; j++)
        {
            if (dateString[i] == numbers[j])
            {
                numChar = 1;
            }
        }
        correctNumChars += numChar;
    }

    return (correctNumChars == 8);
}

bool BudgetDataManager::dateTest2(string dateString)
{
    return (dateString.length() == 10);
}

bool BudgetDataManager::dateTest3(string dateString)
{
    return (dateString[4] == '-' && dateString[7] == '-');
}

bool BudgetDataManager::dateTest4(string dateString)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    string buffer = dateString;
    dateString.erase(4, 9);
    int yearInt = HelpfulMethods::convertStringToInt(dateString);

    return (2000 <= yearInt && yearInt <= st.wYear);
}

bool BudgetDataManager::dateTest5(string dateString)
{
    string buffer = dateString;

    dateString = buffer;
    dateString.erase(0, 5);
    dateString.erase(2, 5);
    int monthInt = HelpfulMethods::convertStringToInt(dateString);

    return (1 <= monthInt && monthInt <= 12 );
}

bool BudgetDataManager::dateTest6(string dateString, bool test5)
{
    string buffer = dateString;
    bool test6_1 = false, test6_2_1 = false, test6_2_2 = false, test6_3 = false;
    int dayInt = HelpfulMethods::getDayIntFromStringDate(dateString);
    int monthInt = HelpfulMethods::getMonthIntFromStringDate(dateString);
    int yearInt = HelpfulMethods::getYearIntFromStringDate(dateString);

    if(test5)
    {
        if((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && 1 <= dayInt && dayInt <= 30)
            test6_1 = true;

        if(monthInt == 2)
        {
            if(((yearInt%100 == 0 && yearInt%400 == 0) || yearInt%4 == 0) && 1 <= dayInt && dayInt <= 29)
                test6_2_1 = true;

            if(1 <= dayInt && dayInt <= 28)
                test6_2_2 = true;
        }

        if((monthInt == 1 || monthInt == 3 || monthInt == 5 || monthInt == 7 || monthInt == 8 || monthInt == 10 || monthInt == 12) && 1 <= dayInt && dayInt <= 31)
            test6_3 = true;
    }

    return (test6_1|| test6_2_1 || test6_2_2 || test6_3);
}

bool BudgetDataManager::dateTest7(string dateString)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    return (HelpfulMethods::convertStringDateToIntDate(dateString) <= (st.wYear*10000 + st.wMonth*100 + st.wDay));
}

vector<BudgetData> BudgetDataManager::sortBudgetDataByDate(vector<BudgetData> budgetDataInVector)
{
    sort(budgetDataInVector.begin(), budgetDataInVector.end(),
         [] (BudgetData& budgetData1, BudgetData& budgetData2)
    {
        return (budgetData1.getDate() < budgetData2.getDate());
    }
        );

    return budgetDataInVector;
}
