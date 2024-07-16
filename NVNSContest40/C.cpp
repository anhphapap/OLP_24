#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'a':
        {
            a++;
            break;
        }
        case 'b':
        {
            b++;
            break;
        }
        case 'c':
        {
            c++;
            break;
        }
        default:
        {
            d++;
            break;
        }
        }
        if (a == b && c > 0 && d == 0)
            ans++;
        int a1 = a,
            b1 = b,
            c1 = c,
            d1 = d;
        for (int j = 0; j <= i - 1; j++)
        {
            switch (s[j])
            {
            case 'a':
            {
                a1--;
                break;
            }
            case 'b':
            {
                b1--;
                break;
            }
            case 'c':
            {
                c1--;
                break;
            }
            default:
            {
                d1--;
                break;
            }
            }
            if (a1 == b1 && c1 > 0 && d1 == 0)
                ans++;
        }
    }
    cout << ans;
    return 0;
}