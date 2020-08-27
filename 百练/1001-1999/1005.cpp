#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int nCase;
    cin >> nCase;
    for(int caseN = 1; caseN <= nCase; ++caseN)
    {
        double x, y;
        cin >> x >> y;

        double pow_r = x*x + y*y;
        double area = 0.5 * M_PI * pow_r;
        double years = area / 50;
        cout << "Property " << caseN <<": This property will begin eroding in year " 
            << (int)years + 1 << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}