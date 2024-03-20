#include <bits/stdc++.h>
using namespace std;

int n, m;
int res = 0;
int f = 0, p = 0;
const int MAXN = 100;
int A[MAXN], x[MAXN];
int u[MAXN];

void Try(int k)
{
    u[k] = (m - f - p);
    if (k == n)
    {
        if (u[k] % A[k] == 0)
        {
            x[k] = u[k] / A[k];
            res++;
        }
        return;
    }
    if (u[k] >= 1)
        for (int v = 1; v <= u[k] / A[k]; v++)
        {
            x[k] = v;
            f = f + A[k] * v;
            p = p - A[k + 1];
            Try(k + 1);
            f = f - A[k] * v;
            p = p + A[k + 1];
        }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 2; i <= n; i++)
        p += A[i];
    Try(1);
    cout << res << endl;
    return 0;
}