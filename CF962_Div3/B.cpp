#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<int>> ans;

bool check(int k, vector<vector<int>> prf, int n)
{
    int z = n / k;
    ans.assign(z, vector<int>(z));
    for (int i = 1; i <= z; i++)
    {
        for (int j = 1; j <= z; j++)
        {
            int sum = prf[i * k][j * k] - prf[(i - 1) * k][j * k] - prf[i * k][(j - 1) * k] + prf[(i - 1) * k][(j - 1) * k];
            if (sum == k * k)
                ans[i - 1][j - 1] = 1;
            else if (sum == 0)
                ans[i - 1][j - 1] = 0;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<vector<int>> prf(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> a(n, vector<int>(n));
        vector<string> s(n);
        for (auto &x : s)
            cin >> x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = (s[i][j] == '0' ? 0 : 1);
                prf[i + 1][j + 1] = a[i][j] + prf[i + 1][j];
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                prf[j + 1][i + 1] += prf[j][i + 1];
        int tmp = k;
        while (tmp > 1 && !check(tmp, prf, n))
        {
            tmp--;
            while (k % tmp != 0)
                tmp--;
        }
        if (tmp == 1)
            for (auto x : a)
            {
                for (auto y : x)
                    cout << y;
                cout << endl;
            }
        else
            for (auto x : ans)
            {
                for (auto y : x)
                    cout << y;
                cout << endl;
            }
    }
    return 0;
}