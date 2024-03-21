#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int y[MAX], x[MAX];
int n, K, q;
int c[MAX][MAX];
int load[MAX] = {0};
int segments = 0, nbR = 0;
int minDist = INT_MAX, f = 0;
int cmin = INT_MAX;
int d[MAX];
bool visited[MAX];

bool checkY(int v, int k)
{
    if (v == 0)
        return true;
    if (load[k] + d[v] > q)
        return false;
    if (visited[v])
        return false;

    return true;
}

bool checkX(int v, int k)
{
    if (v == 0)
        return true;
    if (visited[v])
        return false;
    if (load[k] + d[v] > q)
        return false;
    return true;
}

void TryX(int s, int k)
{
    if (s == 0)
    {
        if (k == K)
            return;
        TryX(y[k + 1], k + 1);
    }
    else
    {
        for (int v = 0; v <= n; v++)
        {
            if (checkX(v, k))
            {
                x[s] = v;
                visited[v] = true;
                f += c[s][v];
                load[k] += d[v];
                segments++;
                if (v > 0)
                {
                    if ((f + (n + nbR - segments) * cmin) < minDist)
                    {
                        TryX(v, k);
                    }
                }
                else
                {
                    if (k == K)
                    {
                        if (segments == n + nbR)
                        {
                            if (f < minDist)
                                minDist = f;
                        }
                    }
                    else
                    {
                        if ((f + (n + nbR - segments) * cmin) < minDist)
                            TryX(y[k + 1], k + 1);
                    }
                }

                visited[v] = false;
                f -= c[s][v];
                load[k] -= d[v];
                segments--;
            }
        }
    }
}

void TryY(int k)
{
    int s = 0;
    if (y[k - 1] > 0)
        s = y[k - 1] + 1;
    for (int v = s; v <= n; v++)
    {
        if (checkY(v, k))
        {
            y[k] = v;
            if (v > 0)
            {
                segments++;
            }
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];

            if (k < K)
                TryY(k + 1);
            else
            {
                nbR = segments;
                TryX(y[1], 1);
            }

            if (v > 0)
            {

                segments--;
            }
            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> K >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            if (i != j && cmin > c[i][j])
                cmin = c[i][j];
        }
    }

    y[0] = 0;
    TryY(1);
    cout << minDist;
}
