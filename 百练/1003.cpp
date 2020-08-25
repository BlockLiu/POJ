#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    double len;
    while(cin >> len)
    {
        if(fabs(len) < 1e-6)
            break;
        double sum = 0;
        int cardNum;
        for(cardNum = 1; ; cardNum++)
        {
            sum += 1.0 / (cardNum + 1);
            double diff = sum - len;
            if(diff > 1e-6)
                break;
        }
        cout << cardNum << " card(s)" << endl;
    }
    return 0;
}