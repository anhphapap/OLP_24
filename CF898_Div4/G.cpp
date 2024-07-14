#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int a = count_if(s.begin(), s.end(), [](char x)
                         { return x == 'A'; });
        int b = count_if(s.begin(), s.end(), [](char x)
                         { return x == 'B'; });
        if (a == 0 || b == 0)
            cout << 0 << endl;
        else if (a <= b || (s[0] == 'B' || s[s.length() - 1] == 'B'))
            cout << a << endl;
        else
        {
            int ans = 0, min = INT_MAX;
            int f = -1, idx = 0;
            while (b--)
            {
                f = s.find('B', f + 1);
                int temp = f - idx;
                min = temp < min ? temp : min;
                ans += temp;
                idx = f + 1;
            }
            if (ans <= a)
            {
                min = (a - ans) < min ? a - ans : min;
                cout << a - min << endl;
            }
        }
    }
    return 0;
}