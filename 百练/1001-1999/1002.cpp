#include <iostream>
#include <string>
#include <map>
#include <assert.h>
using namespace std;

inline char MapCharToNum(char c)
{
    // assert(c >='A' && c <= 'Z' && c != 'Q' && c != 'Z');
    if(c <= 'R')
        return '2' + ((c - 'A') / 3);
    if(c == 'S')
        return '7';
    if(c == 'T' || c == 'U' || c == 'V')
        return '8';
    if(c == 'W' || c == 'X' || c == 'Y')
        return '9';
}

string getNumberFrom(string s)
{
//    cout << "getNumberFrom: " << s;
    string res(7, '0');
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= '0' && s[i] <= '9')
            res[cnt++] = s[i];
        else if(s[i] != '-')
            res[cnt++] = MapCharToNum(s[i]);
    }
    assert(cnt == 7);
//    cout << "\t=>\t" << res << endl;
    return res;
}

int main()
{
    map<string, int> M;
    int nItem;
    cin >> nItem;
    while(nItem--)
    {
        string str;
        cin >> str;
        str = getNumberFrom(str);
        M[str]++;
    }

    int cnt = 0;
    for(auto it = M.begin(); it != M.end(); ++it)
        if(it->second > 1)
        {
            cout << (it->first).substr(0, 3) << "-" << (it->first).substr(3, 4) << " " << it->second << endl;
            cnt++;
        }
    if(!cnt)
        cout << "No duplicates." << endl;
    return 0;
}