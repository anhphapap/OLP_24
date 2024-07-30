#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct ticket
{
    int u, v, m;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ticket> a = {
        {12, 13, 20}, {7, 9, 15}, {9, 10, 8}, {10, 11, 9}, {8, 9, 12}, {13, 15, 5}, {10, 14, 30}, {7, 8, 20}};
    int n = a.size();
    sort(a.begin(), a.end(), [](auto x, auto y)
         { return x.u < y.u; });
    vector<int> t(n, 0);
    t[n - 1] = a[n - 1].m;
    int mx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        t[i] = a[i].m;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].v <= a[j].u && t[j] + a[i].m > t[i])
            {
                t[i] = t[j] + a[i].m;
            }
        }
        mx = t[i] > mx ? t[i] : mx;
    }
    cout << mx;
    return 0;
}