#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

string Hmonth[] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", 
    "yoxkin", "mol", "chen", "yax", "zac", "ceh",
    "mac", "kankin", "muan", "pax", "koyab", "cumhu",
    "uayet"};

string periods[] = {
    "imix", "ik", "akbal", "kan", "chicchan", 
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"}; 

inline int getHMonth(string month)
{
    for(int i = 0; i < 19; ++i)
        if(month == Hmonth[i])
            return i;
    return -1;
}



int main()
{
    int nCase;
    cin >> nCase;
    cout << nCase << endl;
    while(nCase--)
    {
        string strDay, strMonth;
        int day, month, year;
        cin >> strDay >> strMonth >> year;
        day = atoi(strDay.c_str());
        month = getHMonth(strMonth);
        day = year * 365 + month * 20 + day;

        int third = day / 260;
        day = day % 260;
        int second = day % 20;
        int first = (day % 13) + 1;

        cout << first << " " << periods[second] << " " << third << endl;
    }

    return 0;
}