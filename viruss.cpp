#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    vector<int> a(k + 1);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x = 0;
        for (int j = i + 1; j > 1; j--)
        {
            x += a[j - 1] * j - 1;
            a[j] = a[j - 1];
        }
        a[0] = x;
    }
    cout << "";
    return 0;
}