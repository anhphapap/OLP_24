// https://leetcode.com/problems/word-ladder-ii/description/
#include <bits/stdc++.h>

using namespace std;

string beginW = "hit", endW = "cog";
vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"}, ans;
vector<bool> mark;
vector<vector<string>> bestAns;
int counter = 0, best = INT_MAX, n;

void update()
{
    if (counter < best)
    {
        best = counter;
        bestAns.clear();
        bestAns.push_back(ans);
    }
    else
        bestAns.push_back(ans);
}

bool check(string a, string b)
{
    if (a.length() != b.length() || a == b)
        return false;
    int c = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            c++;
            if (c > 1)
                return false;
        }
    }
    return true;
}

void process(string cur)
{
    if (counter > best)
        return;
    for (int i = 0; i < n; i++)
    {
        if (check(cur, words[i]) && !mark[i])
        {
            mark[i] = true;
            ans.push_back(words[i]);
            counter++;
            if (words[i] == endW)
            {
                if (counter <= best)
                    update();
            }
            else
                process(words[i]);
            counter--;
            ans.pop_back();
            mark[i] = false;
        }
    }
}

void output()
{
    for (auto x : bestAns)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}

int main()
{
    int check = count_if(words.begin(), words.end(), [](string s)
                         { return s == endW; });
    n = words.size();
    mark.resize(n, false);
    ans.push_back(beginW);
    if (check > 0)
    {
        process(beginW);
        output();
    }
    else
    {
        return 0;
    }
    return 0;
}
