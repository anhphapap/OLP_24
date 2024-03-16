#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000006;
int n, d[MAX], maxCnt = -1, ans, a[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("prime.inp", "r", stdin);
    freopen("prime.out", "w", stdout);
    // Dùng sàn để biết đc ước ngto nhỏ nhất của số đang xét
    for (int i = 2; i <= MAX; i++)
        if (d[i] == 0)
            for (int j = i; j <= MAX; j += i)
                d[j] = i;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int cnt = 0;
        int tmp = a[i];
        while (tmp > 1)
        {
            cnt++;
            int j = d[tmp];
            while (tmp % j == 0)
                tmp /= j;
        }
        if (cnt > maxCnt)
        {
            maxCnt = cnt;
            ans = a[i];
        }
    }
    cout << ans;
    return 0;
}