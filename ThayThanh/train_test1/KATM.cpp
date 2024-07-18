#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> a, ans, bestAns;
vector<bool> mark;
int counter = 0, bestCounter = INT_MAX;
int dem = 0;

void process(int val)
{
    if (counter > bestCounter)
        return;
    dem++;
    for (int i = 0; i < n; i++)
    {
        if (!mark[i] && a[i] <= val)
        {
            mark[i] = true;
            val -= a[i];
            ans.push_back(a[i]);
            counter++;
            if (val == 0)
            {
                if (counter < bestCounter)
                {
                    bestCounter = counter;
                    bestAns = ans;
                }
            }
            else
                process(val);
            counter--;
            ans.pop_back();
            val += a[i];
            mark[i] = false;
        }
    }
}

int main()
{
    cin >> n >> s;
    a.resize(n);
    mark.resize(n, false);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    process(s);
    for (int x : bestAns)
        cout << x << " ";
    cout << dem;
    return 0;
}