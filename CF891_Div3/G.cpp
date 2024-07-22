#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 998244353;

ll pow1(int x, int y)
{
    ll ans = 1;
    while (y--)
    {
        ans *= x;
        ans %= MOD;
    }
    return ans;
}

struct union_find
{
    vector<int> data;
    int components;

    union_find(int n = -1)
    {
        if (n > 0)
            init(n);
    }

    void init(int n)
    {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x)
    {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x)
    {
        return -data[find(x)];
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        vector<array<int, 3>> edge(n - 1);
        for (auto &x : edge)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            x = {w, u, v};
        }
        sort(edge.begin(), edge.end());
        union_find UF(n);
        ll ans = 1;
        
        for (auto x : edge)
        {
            int w = x[0], u = x[1], v = x[2];
            int a = UF.get_size(u), b = UF.get_size(v);
            ll pairs = (ll)a * b - 1;
            int choices = s - w + 1;
            ans *= pow1(choices % MOD, pairs % MOD);
            ans %= MOD;
            UF.unite(u, v);
        }
        cout << ans << endl;
    }
    return 0;
}