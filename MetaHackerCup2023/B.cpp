#include <bits/stdc++.h>

using namespace std;

ifstream fi("./dim_sum_delivery_input.txt");
ofstream fo("./dim_sum_delivery_output.txt");


int main()
{
    int t, r, c, a, b;
    fi >> t;
    for (int i = 1; i <= t; i++)
    {
        fi >> r >> c >> a >> b;
        fo << "Case #" << i << ": ";
        if (r - 1 > c - 1)
            fo << "YES\n";
        else
            fo << "NO\n";
    }
    fi.close();
    fo.close();
    return 0;
}