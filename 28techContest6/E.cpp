#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int low = 0, high = n - 1, ans = 0;
    while (low < high)
    {
        while (a[low] < a[low + 1])
            low++;
        while (a[high - 1] < a[high])
            high--;
        swap(a[low], a[high]);
        ans++;
        low++;
        high--;
    }
    cout << ans;
    return 0;
}