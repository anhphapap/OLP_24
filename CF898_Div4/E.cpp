#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, w;
    cin >> t;
    const int INF = 1e9 + 5;
    while (t--)
    {
        cin >> n >> w;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        auto process = [&](int m) -> bool
        {
            long long sum = 0;
            for (int x : a)
            {
                if (x < m)
                    sum += m - x;
            }
            return sum <= w;
        };

        int low = 0, high = 2 * INF;
        while (low < high)
        {
            int mid = low + (high - low + 1) / 2;
            if (process(mid))
                low = mid;
            else
                high = mid - 1;
        }
        cout << low << endl;
    }
    return 0;
}