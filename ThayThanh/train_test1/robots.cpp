#include <bits/stdc++.h>

using namespace std;

string robot[9], s, ans = "", bestAns = "0", target = "TTTTTTTTT";
vector<int> mark(9, 0);
int best = INT_MAX;

void draw(string &s, int idx)
{
    for (char x : robot[idx])
    {
        int i = x - '0' - 1;
        switch (s[i])
        {
        case 'V':
        {
            s[i] = 'T';
            break;
        }
        case 'T':
        {
            s[i] = 'X';
            break;
        }
        case 'X':
        {
            s[i] = 'V';
            break;
        }
        }
    }
}

int choose()
{
    int m = -1;
    int idx = -1;

    for (int i = 0; i < 9; i++)
    {
        if (mark[i] < 2)
        {
            int cnt = 0;
            string tmp = s;
            draw(tmp, i);
            for (char x : tmp)
                if (x == 'T')
                    cnt++;
            if (cnt > m)
            {
                m = cnt;
                idx = i;
            }
        }
    }
    return idx;
}

void process(int idx)
{
    int c = choose();
    if (c == -1)
        return;
    draw(s, c);
    ans += '1' + c;
    mark[c]++;
    if (s == target && idx < best)
    {
        best = idx;
        bestAns = ans;
    }
    else
        process(idx + 1);
    mark[c]--;
    ans.pop_back();
    draw(s, c);
    draw(s, c);
}

int main()
{
    for (string &x : robot)
        cin >> x;
    cin >> s;
    process(1);
    cout << bestAns;
    return 0;
}