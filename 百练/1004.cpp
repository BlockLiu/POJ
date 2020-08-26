#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double money = 0, tmp;
    for(int i = 0; i < 12; ++i){
        cin >> tmp;
        money += tmp;
    }
    cout << "$" << fixed << setprecision(2) << money / 12 << endl;
    return 0;
}