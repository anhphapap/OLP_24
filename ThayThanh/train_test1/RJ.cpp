#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, z, t, k;
string s, ans, bestAns, rj = "RJ";
vector<vector<int>> a;
pair<int, int> S[2], E[2];

bool go(int idx, char c)
{
    switch (c)
    {
    case 'N':
    {
        S[idx].first = S[idx].first - 1;
        break;
    }
    case 'S':
    {
        S[idx].first = S[idx].first + 1;
        break;
    }
    case 'E':
    {
        S[idx].second = S[idx].second + 1;
        break;
    }
    case 'W':
    {
        S[idx].second = S[idx].second - 1;
        break;
    }
    }
}

void back(int idx, char c)
{
    switch (c)
    {
    case 'N':
    {
        int row = S[idx].first + 1;
        S[idx].first = row;
        break;
    }
    case 'S':
    {
        int row = S[idx].first - 1;
        S[idx].first = row;
        break;
    }
    case 'E':
    {
        int col = S[idx].second - 1;
        S[idx].second = col;
        break;
    }
    case 'W':
    {
        int col = S[idx].second + 1;
        S[idx].second = col;
        break;
    }
    }
}

bool check(int idx, char c)
{
    switch (c)
    {
    case 'N':
    {
        int row = S[idx].first - 1;
        int col = S[idx].first;
        if (row >= 0 && row < n && a[row][col] == 0)
            return true;
        return false;
    }
    case 'S':
    {
        int row = S[idx].first + 1;
        int col = S[idx].first;
        if (row >= 0 && row < n && a[row][col] == 0)
            return true;
        return false;
    }
    case 'E':
    {
        int row = S[idx].first;
        int col = S[idx].second + 1;
        if (col >= 0 && col < m && a[row][col] == 0)
            return true;
        return false;
    }
    case 'W':
    {
        int row = S[idx].first;
        int col = S[idx].second - 1;
        if (col >= 0 && col < m && a[row][col] == 0)
            return true;
        return false;
    }
    }
}
bool haveAns = false;
void process(int idx)
{
    if (haveAns)
        return;
    for (int i = 0; i < 2; i++)
    {
        if (check(i, s[idx]))
        {
            ans[idx] = rj[i];
            go(i, s[idx]);
            if (idx == k - 1)
            {
                if (S[0] == E[0] && S[1] == E[1])
                {
                    bestAns = ans;
                    haveAns = true;
                }
            }
            else
                process(idx + 1);
            back(i, s[idx]);
        }
    }
}

int main()
{
    cin >> n >> m;
    S[0] = {0, 0};
    S[1] = {n - 1, m - 1};
    a.resize(n, vector<int>(m));
    for (auto &row : a)
        for (auto &cell : row)
            cin >> cell;
    cin >> x >> y >> z >> t >> k >> s;
    E[0] = {x - 1, y - 1};
    E[1] = {z - 1, t - 1};
    ans = s;
    process(0);
    cout << bestAns << endl
         << counter;
    return 0;
}