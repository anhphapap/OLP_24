#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, q;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<vector<int>> cnt(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            int dif = 0;
            for (int j = i; j <= n; j++)
            {
                dif += (a[j - 1] != b[j - 1] ? 2 : 0);
                cnt[i][j] = cnt[i][j - 1] + dif;
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << cnt[l][r] / 2 << endl;
        }
    }
    return 0;
}