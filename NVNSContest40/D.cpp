#include <bits/stdc++.h>

using namespace std;

long long gt(int n)
{
    long long ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}

int main()
{
    int n;
    string s;
    map<char, int> a;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        a[s[i]]++;
    long long ans = gt(n);
    for (auto x : a)
        ans /= gt(x.second);
    int res = 0;
    while (ans % 10 == 0)
    {
        res++;
        ans /= 10;
    }
    cout << res;
    return 0;
}