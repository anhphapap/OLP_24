#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("CAU2.INP", "r", stdin);
    // freopen("CAU2.OUT", "w", stdout);
    map<int, int> a;
    int n, x, ans = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[x]++;
        if (a[x] > ans)
            ans = a[x];
    }
    cout << ans;
    return 0;
}