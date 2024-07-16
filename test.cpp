#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p, q;
    cin >> p >> q >> n;
    vector<bool> a(n + 1, true);
    for (int i = 2; i <= n / 2; i++)
        for (int j = i; j <= n; j += i)
            a[j] = !a[j];
    int ans = 0;
    if (q <= n / 2)
    {
        for (int i = p; i <= q; i++)
            if (a[i])
                ans++;
    }
    else
    {
        for (int i = p; i <= n / 2; i++)
            if (a[i])
                ans++;
        int temp = count_if(a.begin() + n / 2 + 1, a.begin() + q, [](bool x)
                            { return x == false; });
        ans += temp;
    }
    cout << ans;
    return 0;
}