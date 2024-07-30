#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int, int>> a = {
        {2, 3}, {4, 9}, {3, 8}, {3, 6}};
    int n = 4, k = 5;
    vector<vector<int>> l(n + 1, vector<int>(k + 1, 0));
    int j = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            l[j][i] = (a[j - 1].first <= i ? max(l[j][i - a[j - 1].first] + a[j - 1].second, l[j - 1][i]) : l[j - 1][i]);
    for (auto x : l)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << l[n][k];
    return 0;
}