#include <bits/stdc++.h>

using namespace std;

int MAX = 1e9;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int x;
        vector<int> b(n * (n - 1) / 2);
        for (int &x : b)
            cin >> x;
        sort(b.begin(), b.end());
        vector<int> a;
        int cur = 0, add = n - 1;
        while (cur < (n - 1) * n / 2)
        {
            a.push_back(b[cur]);
            cur += add--;
        }
        a.push_back(a.back());
        for (int &x : a)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}