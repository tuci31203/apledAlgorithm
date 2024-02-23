#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
    cin >> a >> b;
    while (a.length() < b.length())
    {
        a = "0" + a;
    }
    while (b.length() < a.length())
    {
        b = "0" + b;
    }
    string res;
    int tmp = 0, nho = 0, i = a.length() - 1;
    while (i >= 0)
    {
        tmp = (a[i] - 48) + (b[i] - 48) + nho;
        nho = tmp / 10;
        res = char(tmp % 10 + 48) + res;
        i--;
    }
    if (nho > 0)
        res = char(nho + 48) + res;
    cout << res;
}