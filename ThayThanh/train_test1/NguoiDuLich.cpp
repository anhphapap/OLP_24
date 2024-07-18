#include <bits/stdc++.h>

using namespace std;

int n, val = 0;
int bestVal = INT_MAX;
vector<int> ans, bestAns;
vector<bool> mark;
vector<vector<int>> a;

void process(int idx)
{
    if (val > bestVal)
        return;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == false && a[ans[idx - 1]][i] > 0)
        {
            ans[idx] = i;
            mark[i] = true;
            val += a[ans[idx - 1]][i];
            if (idx == n - 1)
            {
                if (a[i][0] > 0 && val + a[i][0] < bestVal)
                {
                    bestVal = val + a[i][0];
                    bestAns = ans;
                }
            }
            else
                process(idx + 1);
            mark[i] = false;
            val -= a[ans[idx - 1]][i];
        }
    }
}

int main()
{
    cin >> n;
    a.resize(n, vector<int>(n));
    mark.resize(n, false);
    ans.resize(n);
    mark[0] = true;
    ans[0] = 0;
    for (int i = 0; i < n; i++)
        for (int &y : a[i])
            cin >> y;
    process(1);
    cout << bestVal << endl;
    for (int x : bestAns)
        cout << x + 1 << "->";
    cout << 1;
    return 0;
}