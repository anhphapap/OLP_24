#include <bits/stdc++.h>

using namespace std;

int n, best = INT_MAX, counter = 0;
string s = "ABC";
string ans = "", bestAns;

bool check(char x)
{
    if (ans.length() < 3)
        return true;
    string temp = ans + x;
    int l = temp.length();
    for (int i = 2; i <= l / 2; i++)
    {
        int n = l - i;
        if (temp.substr(n, i) == temp.substr(n - i, i))
            return false;
    }
    return true;
}

void process(int idx)
{
    if (counter >= best)
        return;
    for (char x : s)
    {
        if (idx == 0 || (ans[idx - 1] != x && check(x)))
        {
            if (x == 'C')
                counter++;
            ans += x;
            if (idx == n - 1)
            {
                if (counter < best)
                {
                    best = counter;
                    bestAns = ans;
                }
            }
            else
                process(idx + 1);
            if (x == 'C')
                counter--;
            ans.pop_back();
        }
    }
}

int main()
{
    cin >> n;
    process(0);
    cout << bestAns << endl
         << best;
    return 0;
}
