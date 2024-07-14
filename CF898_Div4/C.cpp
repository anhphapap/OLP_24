#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int ans = 0;
        for (int i = 1; i <= 10; i++)
        {
            cin >> s;
            for (int j = 1; j <= 10; j++)
            {
                if (s[j - 1] == 'X')
                {
                    int id1 = (i <= 5) ? i : (6 - (i - 5));
                    int id2 = (j <= 5) ? j : (6 - (j - 5));
                    ans += min(id1, id2);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}