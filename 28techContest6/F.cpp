#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    // sort(a.begin(),a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 || a[i] == 1)
            continue;
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = low + (high - low + 1) / 2;
            if (b[mid] < a[i])
                low = mid;
            else
                high = mid - 1;
            low++;
            high--;
        }
        if (a[i] == 3 && binary_search(b.begin(), b.end(), 2))
        {
            ans++;
        }
        for (int j = low; j < m; j++)
        {
            if ((a[i] == 2 && b[j] == 4))
                continue;
            ans++;
        }
    }
    cout << ans;
    return 0;
}