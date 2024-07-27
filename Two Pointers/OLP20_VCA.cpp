#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt[256];
    int ans = INT_MAX;
    cnt['V'] = cnt['A'] = cnt['C'] = 0;
    for (int l = 0, r = -1; l < s.length(); --cnt[s[l++]])
    {
        int len = s.length();
        while ((r < len) && (cnt['V'] < n || cnt['A'] < n || cnt['C'] < n))
            ++cnt[s[++r]];
        if (cnt['V'] < n || cnt['A'] < n || cnt['C'] < n)
            break;

        int t = 0;
        t += cnt['A'] + cnt['V'] + cnt['C'] - 3 * n;
        ans = (t < ans) ? t : ans;
    }

    cout << ans;
    return 0;
}
