#include <bits/stdc++.h>

using namespace std;

bool check(long long a)
{
    if ((sqrt(a) == (long long)sqrt(a) && a > 0) || cbrt(a) == (long long)cbrt(a))
        return true;
    return false;
}

int main()
{
    long long t, n;
    ifstream fi("dtl23_a.txt");
    fi >> t;
    while (t--)
    {
        fi >> n;
        if (check(n))
            cout << "Piccolo\n";
        else
            cout << "Majin Buu\n";
    }
    fi.close();
    return 0;
}