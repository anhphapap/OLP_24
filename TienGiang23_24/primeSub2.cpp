#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("prime.inp","r",stdin);
    freopen("prime.out","w",stdout);
    int n, ans, maxCnt = -1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int cnt = 0;
        int tmp = a[i];
        //Tính số các ước nguyên tố của 1 số
        for (int j = 2; j * j <= tmp; j++)
        {
            if (tmp % j == 0)
            {
                cnt++;
                while (tmp % j == 0)
                    tmp /= j;
            }
        }
        if (tmp > 1)
            cnt++;
        if (cnt > maxCnt)
        {
            ans = a[i];
            maxCnt = cnt;
        }
    }
    cout << ans;
    return 0;
}