#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, w;
};

struct Node
{
    int u;
    long long minDis;
};

int t, n, m;
vector<vector<Edge>> e;
vector<long long> minTotal;
vector<bool> mark;
vector<int> s;

void dijkstra()
{
    auto cmp = [](Node p1, Node p2)
    { return p1.minDis > p2.minDis; };
    priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);
    q.push({1, 0});
    minTotal[1] = 0;

    while (!q.empty())
    {
        Node temp = q.top();
        q.pop();

        if (mark[temp.u] == false)
        {
            mark[temp.u] = true;

            for (auto x : e[temp.u])
            {
                if (minTotal[x.u] > minTotal[temp.u] + x.w * s[temp.u])
                {
                    minTotal[x.u] = minTotal[temp.u] + x.w * s[temp.u];
                    q.push({x.u, minTotal[x.u]});
                }
            }
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        e.resize(n + 1);
        minTotal.resize(n + 1, LONG_LONG_MAX);
        mark.resize(n + 1, false);
        s.resize(n + 1);
        int x, y, z;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            e[x].push_back({y, z});
            e[y].push_back({x, z});
        }
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        dijkstra();
        cout << minTotal[n] << endl;
        mark.clear();
        minTotal.clear();
        e.clear();
    }
    return 0;
}