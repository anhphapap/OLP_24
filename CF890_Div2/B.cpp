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
        vector<int> a(n);
        ll sum = 0;
        for (int &x : a)
        {
            cin >> x;
            sum += x;
        }
        ll sum2 = 0;
        for (int x : a)
            sum2 += (x == 1 ? 2 : 1);
        cout << (n > 1 && sum >= sum2 ? "YES" : "NO") << endl;
    }
    return 0;
}