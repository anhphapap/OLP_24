#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> ans;
        string s = to_string(n);
        int l = s.length();
        for (int i = 1; i <= 6; i++)
        {
            string v;
            for (int j = 0; j < i; j++)
                v += s[j % l];
            int val = stoll(v);
            for (int j = 1; j <= 10000; j++)
            {
                a = j;
                b = n * a - val;
                if (b >= 1 && b <= 10000 && l * a - b == i)
                {
                    ans.push_back({a, b});
                }
            }
        }
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}