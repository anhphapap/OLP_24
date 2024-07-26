#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt[256];
        cnt['0'] = cnt['1'] = 0;
        ll ans = 0;
        vector<pair<int, int>> a(s.length() + 1);
        a[0].first = a[0].second = 0;
        for (int i = 0; i < s.length(); i++)
        {
            cnt[s[i]]++;
            a[i + 1].first = cnt['0'];
            a[i + 1].second = cnt['1'];
        }
        for (int i = 2; i <= s.length(); i++)
            for (int j = 1; j < i; j++)
                if (a[i].first - a[j - 1].first == a[i].second - a[j - 1].second)
                    ans++;
        ans %= int(1e9) + 7;
        cout << ans << endl;
    }
    return 0;
}