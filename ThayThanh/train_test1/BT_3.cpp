// https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>

using namespace std;

int n = 6;
vector<vector<string>> ans;
vector<int> queen;

void saveAns()
{
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
        {
            if (queen[i] == j)
                temp += 'Q';
            else
                temp += '.';
        }
        s.push_back(temp);
    }
    ans.push_back(s);
}

bool canPutQueen(int x, int y)
{
    for (int i = x - 1; i >= 0; i--)
    {
        if (queen[i] == y || abs(queen[i] - y) == abs(i - x))
            return false;
    }
    return true;
}

void process(int idx)
{
    for (int i = 0; i < n; i++)
    {
        if (canPutQueen(idx, i))
        {
            queen[idx] = i;
            if (idx == n - 1)
                saveAns();
            else
                process(idx + 1);
        }
    }
}

void output()
{
    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << endl;
        cout << "===========\n";
    }
}

int main()
{
    queen.resize(n);
    process(0);
    output();
    return 0;
}