#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll t, n, q, x, y, z, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<ll, ll> m;
        for (int i = 0; i < n; i++)
        {
            cin >> z;
            m[z]++;
        }
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> x >> y;
            ll ans = [&]() -> ll
            {
                ll temp = sqrt(x * x - 4 * y);
                if (temp * temp != x * x - 4 * y)
                    return 0;
                a = temp + x;
                if (a % 2 != 0)
                    return 0;
                a /= 2;
                b = x - temp;
                if (b % 2 != 0)
                    return 0;
                b /= 2;
                if (a == b)
                    return m[a] * (m[a] - 1) / 2;
                else
                    return m[a] * m[b];
            }();
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}