#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, k;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> s;
        s = 'L' + s + 'L';
        int cur = 0;
        int sw = 0;
        while (cur <= n)
        {
            if (s[cur] == 'C')
                break;

            if (s[cur] == 'W')
            {
                cur++;
                sw++;
                continue;
            }

            if(s[cur] == 'L'){
                bool jump = false;

                for (int i = min(cur + m, n + 1); i > cur; i--)
                {
                    if (s[i] == 'L')
                    {
                        jump = true;
                        cur = i;
                        break;
                    }
                }

                if (jump)
                    continue;

                for (int i = min(cur + m, n + 1); i > cur; i--)
                {
                    if (s[i] == 'W')
                    {
                        jump = true;
                        cur = i;
                        break;
                    }
                }

                if (!jump)
                    break;
            }
        }
        cout << (cur > n && sw <= k ? "YES" : "NO") << endl;
    }
    return 0;
}