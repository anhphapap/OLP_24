#include <bits/stdc++.h>

using namespace std;

ifstream fi("cheeseburger_corollary_2_input.txt");
ofstream fo("cheeseburger_corollary_2_output.txt");

int main()
{
    long long t, a, b, c;
    fi >> t;
    for (int i = 1; i <= t; i++)
    {
        fi >> a >> b >> c;
        long long p = (c / b) * 2 + (c % b) / a;
        long long k = (c / b) * 2 + (c % b) / a * 2;
        long long ans = 0, ans2 = 0;
        if (k > p)
            ans = p;
        else if (k == 0)
            ans = 0;
        else
            ans = k - 1;
        p = (c / a) + (c % a) / b * 2;
        k = (c / a) * 2 + (c % a) / b * 2;
        if (k > p)
            ans2 = p;
        else if (k == 0)
            ans2 = 0;
        else
            ans2 = k - 1;
        fo << "Case #" << i << ": " << max(ans, ans2) << endl;
    }
    fi.close();
    fo.close();
    return 0;
}