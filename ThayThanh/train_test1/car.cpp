#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, ans = 0, cnt = 0;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, float>> c(n);
    vector<int> res;
    for (int &x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c[i].first = i;
        c[i].second = (float)a[i] / b[i];
    }
    sort(c.begin(), c.end(), [&](pair<int, float> a, pair<int, float> b)
         { return a.second > b.second; });
    for (auto x : c)
    {
        int idx = x.first;
        cnt += b[idx];
        ans += (cnt * a[idx]);
    }
    cout << ans << endl;
    for (auto x : c)
        cout << x.first + 1 << " ";
    cout << endl;
    return 0;
}