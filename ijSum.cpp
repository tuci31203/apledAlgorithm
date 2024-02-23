#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum[n] = {0};
    sum[0] = 0;
    int i = 1;
    while (i <= n)
    {
        cin >> arr[i];
        sum[i] += sum[i - 1] + arr[i];
        i++;
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            cout << "Please enter a and b whereas a <= b";
            return 0;
        }
        cout << sum[b] - sum[a - 1] << endl;
        q--;
    }
}