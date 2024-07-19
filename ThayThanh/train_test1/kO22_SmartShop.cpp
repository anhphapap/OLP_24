#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 5;
int n, m;
vector<int> a, prf;
vector<bool> check(MAX, false);
vector<int> p = {2, 3, 5};
int counter(int x, int y)
{
    int low = upper_bound(a.begin(), a.end(), x) - a.begin();
    int high = lower_bound(a.begin(), a.end(), y) - a.begin();
    while (a[high + 1] == y)
        high++;
    while (a[low - 1] == x)
        low--;
    return prf[high + 1] - prf[low];
}

int main()
{
    cin >> n >> m;
    a.resize(n);
    prf.resize(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    check[1] = true;
    for (int x : p)
    {
        check[x] = true;
        for (int i = x * x; i < MAX; i = i * x)
            check[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (check[a[i]])
            prf[i + 1] += prf[i] + 1;
        else
            prf[i + 1] += prf[i];
    }
    int l, h;
    while (m--)
    {
        cin >> l >> h;
        cout << counter(l, h) << endl;
    }

    return 0;
}