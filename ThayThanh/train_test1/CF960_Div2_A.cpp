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
        int m = -1, cnt = 0;
        vector<int> a(n);
        for (int &x : a)
        {
            cin >> x;
            if (x > m)
            {
                m = x;
                cnt = 1;
            }
            else if (m == x)
            {
                cnt++;
            }
        }
        if (cnt % 2 == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}