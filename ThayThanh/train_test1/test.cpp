#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a = {1, 2, 3, 4, 5, 7, 8};
    cout << a.size() << endl;
    a.erase(a.begin() + 1);
    cout << a.size() << endl;
    for (int x : a)
        cout << x << " ";
    return 0;
}