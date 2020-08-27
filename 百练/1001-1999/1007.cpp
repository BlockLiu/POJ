#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getInverse(string &str)
{
    int ret = 0;
    int count[4][60] = {0};         // A, C, G, T
    for(int i = str.size() - 1; i >= 0; --i){
        switch(str[i])
        {
            case 'A':{
                count[0][i] = 1;  
                break;
            }
            case 'C':{
                ret += count[0][i + 1];
                count[1][i] = 1;  
                break;
            }
            case 'G':{
                ret += count[0][i + 1] + count[1][i + 1];
                count[2][i] = 1;  
                break;
            }
            case 'T':{
                ret += count[0][i + 1] + count[1][i + 1] + count[2][i + 1];
                count[3][i] = 1;  
                break;
            }
        }
        for(int k = 0; k < 4; ++k)
            count[k][i] += count[k][i + 1];
    }
    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > rec;
    string str[100];
    for(int i = 0; i < m; ++i)
    {
        cin >> str[i];
        rec.push_back(pair<int, int>(getInverse(str[i]), i));
    }

    sort(rec.begin(), rec.end(), [](pair<int, int> &p1, pair<int, int> &p2){
        return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
    });

    for(int i = 0; i < rec.size(); ++i)
        cout << str[rec[i].second] << endl;

    return 0;
}