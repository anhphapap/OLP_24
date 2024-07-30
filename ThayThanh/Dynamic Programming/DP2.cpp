#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int>> a = {
        {11, 13}, {7, 9}, {9, 10}, {10, 11}, {8, 9}, {13, 15}, {13, 14}, {14, 16}};
    int n = a.size();
    vector<int> l(n, 1), prev(n, -1);
    sort(a.begin(), a.end(), [&](auto x, auto y)
         { return x.first < y.first; });
    int mx = -1, idx;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].second <= a[j].first && l[i] < l[j] + 1)
            {
                l[i] = l[j] + 1;
                prev[i] = j;
            }
        }
        if (l[i] > mx)
        {
            mx = l[i];
            idx = i;
        }
    }
    while (idx != -1)
    {
        cout << a[idx].first << " " << a[idx].second << endl;
        idx = prev[idx];
    }
    return 0;
}