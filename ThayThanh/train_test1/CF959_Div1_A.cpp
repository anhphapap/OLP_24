#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int N = n * m;
        vector<int> a(N);
        for (int &x : a)
            cin >> x;
        if (N == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (N % 2 != 0)
            swap(a[N / 2], a[N / 2 + 1]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << a[--N] << " ";
            cout << endl;
        }
    }
    return 0;
}
