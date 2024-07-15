#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(4, 0);
    if (n % 3 == 1)
        a[1]++;
    if (n % 3 == 2)
    {
        a[1]++;
        a[2]++;
    }
    a[1] += n / 3;
    a[2] += n / 3;
    a[3] += n / 3;
    int temp = m;
    int i = 1;
    while (temp - a[i] > 0)
    {
        temp -= a[i];
        i++;
    }
    int ans = 0;
    while (--temp)
        ans += 3;
    ans += i;
    cout << ans;
    return 0;
}