#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    int cnt = 0, c = 0, x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 0)
        {
            c++;
            if (c == d)
            {
                cnt++;
                c = 0;
            }
        }
        else
            c = 0;
    }
    cout << cnt;
    return 0;
}
