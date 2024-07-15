#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    long long ans = max(a + c, max(b, d));
    cout << ans * ans;
    return 0;
}