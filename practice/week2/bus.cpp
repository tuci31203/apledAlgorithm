#include <bits/stdc++.h>
using namespace std;

int n, cap, mm = INT_MAX;
int load = 0, f = 0, minDist = INT_MAX;
bool visited[10000];
int d[1000][1000];
int x[1000];

bool check(int v)
{
    if (v <= n)
    {
        return (!visited[v] && load < cap);
    }
    else
    {
        return (!visited[v] && visited[v - n]);
    }
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
        if (check(v))
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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