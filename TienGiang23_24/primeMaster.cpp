#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000006;
int n, cnt[MAX], maxCnt = -1, ans, a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("prime.inp", "r", stdin);
    freopen("prime.out", "w", stdout);
    cin >> n;
    // Sàng số nguyên tố nma đếm hẳn luôn
    for (int i = 2; i <= MAX; i++)
    {
        if (cnt[i] == 0)
            for (int j = i; j <= MAX; j += i)
                cnt[j]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (cnt[a] > maxCnt)
        {
            maxCnt = cnt[a];
            ans = a;
        }
    }
    cout << ans;
    return 0;
}
