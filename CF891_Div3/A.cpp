#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int x, ans = 0;
        while (n--)
        {
            cin >> x;
            ans += x;
        }
        if (ans % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}