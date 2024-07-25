#include <bits/stdc++.h>

using namespace std;

int n;
long long a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (a == 0)
        {
            cout << 0 << " " << 1 << endl;
            continue;
        }
        \
        if ((a > 0 && b > 0) || (a < 0 && b < 0))
        {
            cout << llabs(a) / llabs(__gcd(a, b)) << " " << llabs(b) / llabs(__gcd(a, b)) << endl;
            continue;
        }
        long long x = a / llabs(__gcd(a, b));
        long long y = b / llabs(__gcd(a, b));
        if (x + y > 0)
            cout << x << " " << y << endl;
        else if (x + y < 0)
            cout << -x << " " << -y << endl;
        else
            cout << 0 << " " << 0 << endl;
    }
    return 0;
}