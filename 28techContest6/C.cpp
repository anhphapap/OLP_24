#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    long long ans = 0;
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (int x : a)
        ans += abs(x - a[n / 2]);
    cout << ans;
    return 0;
}