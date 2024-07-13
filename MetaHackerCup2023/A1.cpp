#include <bits/stdc++.h>

using namespace std;

ifstream fi("./cheeseburger_corollary_1_input.txt");
ofstream fo("cheeseburger_corollary_1_output.txt");

int main()
{
    int t, s, d, k, b, p, tc = 0;
    fi >> t;
    while (t--)
    {
        tc++;
        fi >> s >> d >> k;
        b = 2 * s + 2 * d;
        p = s + 2 * d;
        fo << "Case #" << tc << ": ";
        if (b >= k + 1 && p >= k)
            fo << "YES\n";
        else
            fo << "NO\n";
    }
    fi.close();
    fo.close();
    return 0;
}