#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll ans = 0;
        int m = -1;
        vector<int> a(n);
        cin >> a[0];
        ans += a[0];
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            ans += a[i];
            if (a[i] > m && a[i - 1] == a[i])
                m = a[i];
            if (m != -1)
                ans += i * m;
            cout << ans << " ";
        }
        cout << ans << endl;
    }
    return 0;
}