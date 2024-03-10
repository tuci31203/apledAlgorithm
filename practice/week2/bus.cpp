#include <bits/stdc++.h>
using namespace std;

int n, cap, mm = INT_MAX;
int load = 0, f = 0, minDist = INT_MAX;
bool visited[10000];
int d[1000][1000];
int x[1000];

bool check(int v, int k)
{
    if (visited[v] == true)
        return false;
    if (v > n)
    {
        if (visited[v - n] == false)
            return false;
    }
    else
    {
        if (load + 1 > cap)
            return false;
    }
    return true;
}

void updateBest()
{
    if (f + d[x[2 * n]][0] < minDist)
        minDist = f + d[x[2 * n]][0];
}

void Try(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            f += d[x[k - 1]][x[k]];
            visited[v] = true;

            if (v <= n)
            {
                load += 1;
            }
            else
                load -= 1;
            if (k == 2 * n)
                updateBest();
            else
            {
                if ((f + mm * (2 * n + 1 - k) < minDist))
                    Try(k + 1);
            }

            if (v <= n)
                load -= 1;
            else
                load += 1;
            f -= d[x[k - 1]][x[k]];
            visited[v] = false;
        }
    }
}

int main()
{
    cin >> n >> cap;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            if (i != j)
                mm = min(mm, d[i][j]);
        }
    }
    x[0] = 0;
    Try(1);
    cout << minDist;
    return 0;
}