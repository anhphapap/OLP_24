#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        vector<int> a(n), h(n), s(n + 1, 0);
        for (int &x : a)
            cin >> x;
        partial_sum(a.begin(), a.end(), s.begin() + 1);
        for (int &x : h)
            cin >> x;
        int ans = 0;
        for (int i = n - 1, end = n; i >= 0; i--)
        {
            if (i + 1 < n && h[i] % h[i + 1] != 0)
                end = i + 1;

            int low = i, high = end;
            while (low < high)
            {
                int mid = low + (high - low + 1) / 2;
                if (s[mid] - s[i] <= k)
                    low = mid;
                else
                    high = mid - 1;
            }
            ans = max(ans, low - i);
        }
        cout << ans << endl;
    }
    return 0;
}