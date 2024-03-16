#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] < a[j])
        {
            ans += a[j];
            j--;
        }
        else
        {
            ans += a[i];
            i++;
        }
        if (a[i] < a[j])
            j--;
        else
            i++;
    }
    cout << ans;
    return 0;
}