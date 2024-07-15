#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> snt(n + 1, true);
    snt[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            snt[j] = false;
        }
    }
    vector<int> b;
    for (int i = 1; i <= n; i++)
        if (snt[i])
            b.push_back(i);
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<long long> prf(n + 1);
    partial_sum(a.begin(), a.end(), prf.begin() + 1);
    long long ans = LONG_LONG_MIN;
    for (int i = 0; i < b.size(); i++)
        for (int j = i; j < b.size(); j++)
            if (prf[b[j]] - prf[b[i] - 1] > ans)
                ans = prf[b[j]] - prf[b[i] - 1];
    cout << ans << endl;
    return 0;
}