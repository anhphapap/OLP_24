#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a = {4, 3, 4, 3, 4, 3, 4, 3};
    int product = 1;
    int s = 1;
    for (auto &x : a)
    {
        product = __gcd(product * x, 6);
        // cout << product << endl;
        if (product == 6)
        {
            s++;
            product = x;
        }
    }
    cout << s;
    return 0;
}