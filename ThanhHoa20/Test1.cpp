#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
    int x, y;
    cin >> x >> y;
    int z = __gcd(x, y), ans = 0;
    for (int i = 1; i <= z; i++)
        if (z % i == 0)
            ans++;
    cout << ans;
    return 0;
}