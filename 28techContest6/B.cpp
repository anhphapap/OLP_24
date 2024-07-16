#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    cout << 0 << " ";
    for (int i = 1; i < n; i++)
    {
        int ans = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j])
            {
                ans = j + 1;
                break;
            }
        }
        cout << ans << " ";
    }
    return 0;
}