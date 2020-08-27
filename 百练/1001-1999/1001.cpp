#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;

class FloatString
{
    string digits;
    int nDAP;       // number of digits after point
public:
    FloatString(string s){
        int pointPos = s.find('.');
        this->nDAP = pointPos == s.npos ? 0 : s.size() - pointPos - 1;

        string A = s.substr(0, pointPos);
        string B = s.substr(pointPos + 1, this->nDAP);
        this->digits = A + B;
        simplify();
    }
    void pow(int n){
        this->nDAP *= n;
        string res = "1", a = digits;
        while(n > 0){
            if (n & 1)
                res = FloatString::multiply(res, a);
            a = FloatString::multiply(a, a);
            n >>= 1;
        }
        this->digits = res;
    }
    const string getNumber(){
        simplify();
        string res = digits.substr(0, digits.size() - nDAP);
        res += nDAP == 0 ? "" : ("." + digits.substr(digits.size() - nDAP, nDAP));
        return res;
    }
private:
    void simplify();
public:
    static string multiply(string a, string b);
    static string multiplyLessThan10(string a, int n);
    static string add(string a, string b);
};

int main()
{
    string x;
    int n;
    while(cin >> x >> n)
    {
        FloatString num(x);
        num.pow(n);
//        cout << "pow(" << x << ", " << n << ") = " << num.getNumber() <<  std::endl;
        cout << num.getNumber() << std::endl;
    }
    return 0;
}

void FloatString::simplify()
{
    if (nDAP >= digits.size())
        digits = string(1 + nDAP - digits.size(), '0') + digits;
    int beg = 0;
    while((beg < digits.size() - nDAP) && (digits[beg] == '0'))
        beg++;
    string A = (beg == digits.size() - nDAP) ? "" : digits.substr(beg, digits.size() - nDAP - beg);

    int end = digits.size() - 1;
    while((end >= digits.size() - nDAP) && (digits[end] == '0'))
        end--;
    string B = digits.substr(digits.size() - nDAP, (end < digits.size() - nDAP) ? 0 : (end + 1 - (digits.size() - nDAP)));
    nDAP = B.size();
    digits = A + B;
}

string FloatString::multiply(string a, string b)
{
    string res = "0";
    for(int i = 0; i < b.size(); ++i)
        if (b[i] != '0') {
            string tmp = multiplyLessThan10(a, b[i] - '0') + string(b.size() - 1 - i, '0');
            res = FloatString::add(res, tmp);
        }
    return res;
}

string FloatString::multiplyLessThan10(string a, int n)
{
    assert(n > 0 && n < 10);
    int offset = 0;
    for(int i = a.size() - 1; i >= 0; --i){
        int tmp = (a[i] - '0') * n + offset;
        a[i] = '0' + (tmp % 10);
        offset = tmp / 10;
    }
    if (offset)
        return string(1, '0' + offset) + a;
    return a;
}

string FloatString::add(string a, string b)
{
    if (a.size() < b.size())
        a = string(b.size() - a.size(), '0') + a;
    b = string(a.size() - b.size(), '0') + b;

    int offset = 0;
    for(int i = a.size() - 1; i >= 0; --i){
        int tmp = offset + (a[i] - '0') + (b[i] - '0');
        a[i] = '0' + (tmp % 10);
        offset = tmp / 10;
    }
    if (offset)
        return string(1, '0' + offset) + a;
    return a;
}