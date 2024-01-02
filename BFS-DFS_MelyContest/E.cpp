#include <bits/stdc++.h>

using namespace std;

int n, m, res = 1e9;

void bfs()
{
    int minC = 1e9;
    queue<pair<int, int>> q;
    q.push({n, 0});

    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();

        if (t.first == m)
        {
            res = min(t.second, minC);
            return;
        }
        else
        {
            if (t.first > m )
            {
                if(t.first - m + t.second < minC)
                    minC = t.first - m + t.second;
            }
            else
            {
                q.push({t.first - 1, t.second + 1});
                q.push({t.first * 2, t.second + 1});
            }
        }
    }
    res = min(res, minC);
}

int main()
{
    cin >> n >> m;
    bfs();
    cout << res;
    return 0;
}