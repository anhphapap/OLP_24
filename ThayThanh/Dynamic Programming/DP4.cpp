#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {3, 1, 5, 6, 8, 2};
    vector<int> b = {1, 2, 4, 3, 6, 8};
    int n = a.size();
    int m = b.size();
    vector<vector<int>> l(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            l[i][j] = (a[i - 1] == b[j - 1] ? l[i - 1][j - 1] + 1 : max(l[i - 1][j], l[i][j - 1]));
    int i = n, j = m;
    while (l[i][j] != 0)
    {
        int val = l[i][j];
        while (l[i][j] == val)
            i--;
        i++;
        while (l[i][j] == val)
            j--;
        i--;
        cout << a[i] << " ";
    }
    return 0;
}