#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s1 = "abc", s;
    while (t--)
    {
        cin >> s;
        bool ans = false;
        for (int i = 0; i < 3; i++)
            if (s[i] == s1[i])
                ans = true;
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}