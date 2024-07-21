#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n + 1);
        bool oce = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] >= 27)
                oce = 0;
        }
        if (a[1] == 1 && n == 1)
        {
            cout << "z\n";
            continue;
        }
        if (a[1] == 1 || oce == 0)
        {
            cout << -1 << '\n';
            continue;
        }
        string res = [&]() -> string
        {
            string ans = "z";
            a[1]--;
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 == 0)
                {
                    char x = 'b';
                    if (x + a[i] - 1 > 'z')
                        return "-1";
                    for (int j = 0; j < a[i]; j++)
                        ans += x++;
                    if (i + 1 <= n)
                    {
                        if (ans[ans.length() - 1] <= 'a' + a[i + 1])
                        {
                            ans[ans.length() - 1] = 'a' + a[i + 1];
                            if ('a' + a[i + 1] > 'z')
                                return "-1";
                        }
                    }
                }
                else
                {
                    char x = 'a' + a[i] - 1;
                    if (x > 'z')
                        return "-1";
                    for (int j = 0; j < a[i]; j++)
                        ans += x--;
                }
            }
            return ans;
        }();
        cout << res << endl;
    }
    return 0;
}
