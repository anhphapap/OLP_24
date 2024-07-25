#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int cnt = 0;
        while (n > 1)
        {
            n -= k - 1;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}