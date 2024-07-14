#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    string s;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> k >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'B')
            {
                ans++;
                i += k - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}