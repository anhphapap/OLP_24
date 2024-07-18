#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int u;
    int dis, mon;
};

int k, n, r;
vector<vector<edge>> a;
int len = 0, cost, bestLen = INT_MAX;

void process(int idx)
{
    if (len > bestLen)
        return;

    for (auto x : a[idx])
    {
        if (x.mon <= cost)
        {
            cost -= x.mon;
            len += x.dis;
            if (x.u == n)
            {
                if (len < bestLen)
                    bestLen = len;
            }
            else
                process(x.u);
            len -= x.dis;
            cost += x.mon;
        }
    }
}

int main()
{
    cin >> k >> n >> r;
    cost = k;
    a.resize(n + 1);
    int x, y, z, t;
    while (r--)
    {
        cin >> x >> y >> z >> t;
        edge temp = {y, z, t};
        a[x].push_back(temp);
    }
    process(1);
    cout << (bestLen == INT_MAX ? -1 : bestLen); 
    return 0;
}