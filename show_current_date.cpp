#include <iostream>
#include <windows.h>
#include <winbase.h>
using namespace std;

int main()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    cout << "Biezacy rok to " << st.wYear<< endl;
    cout << "Biezacy miesiac to " << st.wMonth<< endl;
    cout << "Biezacy dzien to " << st.wDay<< endl;

    return 0;
}
