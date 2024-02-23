#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> sl;
    int t;
    cin >> t;
    while (t > 0)
    {
        int a, b;
        cin >> a >> b;
        while (a > 0)
        {
            int tmp;
            cin >> tmp;
            sl[tmp]++;
            a--;
        }
        while (b > 0)
        {
            int tmp;
            cin >> tmp;
            sl[tmp]--;
            b--;
        }

        int res = 0;

        for (map<int, int>::iterator it = sl.begin(); it != sl.end(); it++)
        {
            res += abs(it->second);
        }

        cout << res;

        t--;
    }
}