#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    const long long MOD = 20240131;
    long long n;
    long long f = 1, ans = 0;
    cin >> n;
    for (int i = 1; i <= min(n, MOD); i++)
    {
        (f *= i) %= MOD;
        (ans += f) %= MOD;
    }
    cout << ans;
    return 0;
}