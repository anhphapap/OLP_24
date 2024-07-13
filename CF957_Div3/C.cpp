#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        reverse(a.begin(), a.end());
        reverse(a.end() - m, a.end());
        for (int x : a)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}