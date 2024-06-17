#include <bits/stdc++.h>

using namespace std;

vector<int> a = {200, 10, 20, 20, 100, 50, 50, 50, 50, 100};
int n = 10, s = 400;
vector<int> ans, bestAns(21);

void process(int idx, int total)
{
    if (idx > bestAns.size())
        return;
    for (int i = 0; i < n; i++)
    {
        if (a[i] + total <= s)
        {
            ans.push_back(a[i]);
            total += a[i];
            if (total == s && idx < bestAns.size())
            {
                bestAns = ans;
            }
            else
                process(idx + 1, total);
            ans.pop_back();
            total -= a[i];
        }
    }
}

void output()
{
    if (bestAns.size() != 21)
        for (int x : bestAns)
            cout << x << " ";
    else
        cout << "-1";
}

int main()
{
    sort(a.begin(), a.end(), [](int a, int b)
         { return a > b; });
    process(1, 0);
    output();
    return 0;
}