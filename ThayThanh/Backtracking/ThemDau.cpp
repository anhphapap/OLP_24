#include <bits/stdc++.h>

using namespace std;

string s = "1234567";
string s1 = s, ans = "";
int m = 8, sum = 0;

void output()
{
    for (int i = 0; i < s.length(); i++)
        cout << s1[i] << s[i];
    cout << endl;
}

void process(int idx)
{
    sum += (s[idx] - '0');
    s1[idx] = '+';
    if (idx == s.length() - 1)
    {
        if (sum == m)
            output();
    }
    else
    {
        process(idx + 1);
        sum -= (s[idx] - '0');
    }
    sum -= (s[idx] - '0');
    s1[idx] = '-';
    if (idx == s.length() - 1)
    {
        if (sum == m)
            output();
    }
    else
    {
        process(idx + 1);
        sum += (s[idx] - '0');
    }
}

int main()
{
    process(0);
    return 0;
}