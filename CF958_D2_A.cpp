#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int i = 1;
        int ans = 0, temp = n;
        if (n >= k)
        {
            if (n % k != 0)
                ans = 2;
            else
                ans = 1;
        }
        while (temp / k >= k)
        {
            ans += pow(k, i);
            i++;
            temp /= k;
        }
        if (temp > k)
            ans += temp / k;
        cout << ans << endl;
    }
    return 0;
}