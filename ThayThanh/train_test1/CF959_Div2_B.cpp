#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    string s1, s2;
    cin >> t;
    while (t--)
    {
        cin >> n >> s1 >> s2;
        bool ans = [&]() -> bool
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (s1[i] == '1')
                    cnt++;
                if (s1[i] != s2[i] && cnt == 0)
                {
                    return false;
                }
            }
            return true;
        }();
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}