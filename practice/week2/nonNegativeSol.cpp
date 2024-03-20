#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int n, m;
int a[MAX];

int countSol()
{
    int res[m + 1] = {0};
    res[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= m; j++)
        {
            res[j] += res[j - a[i]];
        }
    }

    return res[m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = countSol() % (1000000007);
    cout << res;
    return 0;
}
