#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k, ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a(k);
        for (int &x : a)
            cin >> x;
        sort(a.begin(), a.end());
        ans = 0;
        for (int i = 0; i < k - 1; i++)
            ans += a[i] * 2 - 1;
        cout << ans << endl;
    }
    return 0;
}