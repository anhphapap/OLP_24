// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>

using namespace std;

string s[10];
string in, s1;
vector<string> ans;
vector<int> arr;
int n;

void Try(int idx)
{
    for (char x : s[arr[idx]])
    {
        s1[idx] = x;
        if (idx == n - 1)
            ans.push_back(s1);
        else
            Try(idx + 1);
    }
}

int main()
{
    s[2] = "abc";
    s[3] = "def";
    s[4] = "ghi";
    s[5] = "mno";
    s[6] = "jkl";
    s[7] = "pqrs";
    s[8] = "tuv";
    s[9] = "wxyz";
    cin >> in;
    s1 = in;
    for (char x : in)
        arr.push_back(x - '0');
    n = arr.size();
    Try(0);
    for (string x : ans)
        cout << x << " ";
    return 0;
}