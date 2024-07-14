#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        long long ans = 1;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        *min_element(a.begin(), a.end()) += 1;
        for (int x : a)
            ans *= x;
        cout << ans << endl;
    }
    return 0;
}