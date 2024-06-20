#include <bits/stdc++.h>

using namespace std;

int a[] = {4, 5, 3, 2, 8, 9};

void process(int l, int r, int &mn, int &mx, int &dif)
{
    if (l == r)
    {
        mn = mx = a[l];
        dif = 0;
    }
    else
    {
        int mid = (l + r) / 2;

        int mn1, mx1, dif1;
        process(l, mid, mn1, mx1, dif1);
        int mn2, mx2, dif2;
        process(mid + 1, r, mn2, mx2, dif2);

        mn = (mn1 < mn2) ? mn1 : mn2;
        mx = (mx1 > mx2) ? mx1 : mx2;

        dif = mx - mn;
        if (dif < dif1)
            dif = dif1;
        if (dif < dif2)
            dif = dif2;
    }
}

int main()
{
    int mn, mx, dif;
    process(0, 5, mn, mx, dif);
    cout << dif;
    return 0;
}