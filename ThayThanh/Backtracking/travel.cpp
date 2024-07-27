/*
5
0 10 20 30 25
10 0 50 40 15
20 50 0 45 20
30 40 45 0 15
25 15 20 15 0
 */
#include <bits/stdc++.h>

using namespace std;

int n = 5;
vector<vector<int>> a = {
    {0, 10, 20, 30, 25},
    {10, 0, 50, 40, 15},
    {20, 50, 0, 45, 20},
    {30, 40, 45, 0, 15},
    {25, 15, 20, 15, 0}};
vector<bool> mark(n, false);
vector<int> way, bestWay;
int bestTotal = INT32_MAX;

void process(int idx, int total, int count)
{
    if (total > bestTotal)
        return;
    for (int i = 0; i < n; i++)
    {
        if (a[idx][i] > 0 && !mark[i])
        {
            mark[i] = true;
            total += a[idx][i];
            way.push_back(i);
            if (count == n - 1 && total + a[i][0] < bestTotal)
            {
                bestTotal = total + a[i][0];
                bestWay = way;
                bestWay.push_back(0);
            }
            else
                process(i, total, count + 1);
            mark[i] = false;
            total -= a[idx][i];
            way.pop_back();
        }
    }
}

void output()
{
    cout << bestTotal << endl;
    for (int x : bestWay)
        cout << x + 1 << " ";
}

int main()
{
    mark[0] = true;
    way.push_back(0);
    process(0, 0, 1);
    output();
    return 0;
}