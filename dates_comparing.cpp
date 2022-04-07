#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

int konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

vector<int> zapisanieDatyWTablicy(string data)
{
    vector<int> dataWTablicy;
    string bufor = data;


    dataWTablicy.push_back(konwersjaStringNaInt(data.erase(4, 6)));

    data = bufor;
    data = data.erase(0, 5);
    dataWTablicy.push_back(konwersjaStringNaInt(data.erase(2, 3)));

    data = bufor;
    dataWTablicy.push_back(konwersjaStringNaInt(data.erase(0, 8)));

    return dataWTablicy;
}

string returnEarlierDate(string data1, string data2)
{
    vector<int> data1WTablicy = zapisanieDatyWTablicy(data1);
    vector<int> data2WTablicy = zapisanieDatyWTablicy(data2);

    for (int i = 0; i < 3; i++)
    {
        if (data1WTablicy[i] < data2WTablicy[i])
        {
            return data1;
        }
        else if (data1WTablicy[i] > data2WTablicy[i])
        {
            return data2;
        }
        else if (data1WTablicy[2] == data2WTablicy[2])
        {
            return "same";
        }
    }
}

int main()
{
    string data = "2022-04-01";
    string data2 = "2022-04-01";

    string result = returnEarlierDate(data, data2);
    cout << result << endl;

    return 0;
}
