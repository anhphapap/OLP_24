#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int low = 0, high = n - 1;
    while (a[low] < a[low + 1])
        low++;
    while (a[high - 1] < a[high])
        high--;
    high--;
    if (low < high)
    {
        while (a[high - 1] > a[high])
            high--;
        if (high == low)
            cout << "28tech";
        else
            cout << "29tech";
    }
    else
        cout << "29tech";
    return 0;
}