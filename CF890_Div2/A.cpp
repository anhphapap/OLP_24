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
        vector<int> a(n + 1);
        int mx = INT_MIN;
        a[0] = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] < a[i - 1])
            {
                if (a[i - 1] > mx)
                    mx = a[i - 1];
            }
        }
        cout << (mx == INT_MIN ? 0 : mx) << endl;
    }
    return 0;
}