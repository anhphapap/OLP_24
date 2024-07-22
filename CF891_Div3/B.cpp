#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        int i = 0;
        while (s[i] < '5')
            i++;
        while (s[i - 1] == '4')
            i--;
        if (i == 0)
        {
            s = '1' + s;
            for (int j = i + 1; j < s.length(); j++)
                s[j] = '0';
        }
        else if (i != s.length())
        {
            s[i - 1]++;
            for (int j = i; j < s.length(); j++)
                s[j] = '0';
        }
        cout << s << endl;
    }
    return 0;
}