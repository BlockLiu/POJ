#include <iostream>
#include <math.h>
using namespace std;

inline int getInverse(int x, int p)     // compute inverse item of x (mod p)
{
    for(int i = 1; i < p; ++i)
        if(((x * i) % p) == 1)
            return i;
    return -1;
}

int main()
{
    int Inverse23 = getInverse(28*33, 23);
    int Inverse28 = getInverse(23*33, 28);
    int Inverse33 = getInverse(23*28, 33);

    int a, b, c, d, caseN = 0;
    while(cin >> a >> b >> c >>d)
    {
        if (a == -1 && b == -1 && c == -1 && d == -1)
            break;
        a %= 23;
        b %= 28;
        c %= 33;

        long long x = a * Inverse23 * 28*33;
        long long y = b * Inverse28 * 23*33;
        long long z = c * Inverse33 * 23*28;

        long long res = (x + y + z) % (23 * 28 * 33);
        if (res <= d)
                res += 23 * 28 * 33;
        cout << "Case " << ++caseN << ": the next triple peak occurs in " << res - d << " days." << endl;
    }
    return 0;
}