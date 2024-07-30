#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {20, 1, 9, 8, 15, 10, 11};
    int n = 7;
    vector<int> l(n, 1), prev(n, -1);
    l[n - 1] = 1;
    int mx = -1, id;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j<n; j++)
        {
            if (a[i] < a[j] && l[j] + 1 > l[i])
            {
                l[i] = l[j] + 1;
                prev[i] = j;
            }
        }
        if (l[i] > mx)
        {
            mx = l[i];
            id = i;
        }
    }
    while (id != -1)
    {
        cout << a[id] << " ";
        id = prev[id];
    }
    return 0;
}