#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e8 + 7;
const int MAX = 1e3 + 3;
int n, m, d[MAX][MAX];
char a[MAX][MAX];
int goX[4] = {-1, 1, 0, 0};
int goY[4] = {0, 0, -1, 1};
long long f[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("ant.inp","r",stdin);
    // freopen("ant.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
    queue<pair<int, int>> q;    
    d[0][0] = 0;
    f[0][0] = 1;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int X = temp.first + goX[i];
            int Y = temp.second + goY[i];
            if (X >= 0 && X < n && Y >= 0 && Y < m && a[X][Y] == '1')
            {
                if (d[X][Y] > d[temp.first][temp.second] + 1)
                {
                    d[X][Y] = d[temp.first][temp.second] + 1;
                    f[X][Y] = f[temp.first][temp.second];
                    q.push({X, Y});
                }
                else if (d[X][Y] == d[temp.first][temp.second] + 1)
                {
                    (f[X][Y] += f[temp.first][temp.second]) %= MOD;
                }
            }
        }
    }
    cout << f[n-1][m-1] << endl
         << d[n-1][m-1];
    return 0;
}

