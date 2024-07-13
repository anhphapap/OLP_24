#include <bits/stdc++.h>

using namespace std;
ifstream fi("c.inp");

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, t;
    fi >> t;
    for (long long i = 1; i <= t; i++)
    {
        fi >> n;
        vector<long long> a(n * 2 - 1);
        for (long long &x : a)
            fi >> x;
        sort(a.begin(), a.end());
        multiset<long long> sorted(a.begin(), a.end());
        long long sum = accumulate(a.begin(), a.end(), 0);
        long long x = n - sum % n;
        long long ans = -1;
        while (true)
        {
            assert((sum + x) % n == 0);
            long long ssub = (sum + x) / n;
            if (x + 1 > ssub)
                break;
            sorted.insert(x);
            auto f = sorted.begin(), l = prev(sorted.end());
            bool fail = true;
            while (*l + *f == ssub)
            {
                f++;
                if (f == l)
                {
                    fail = false;
                    break;
                }
                l--;
            }
            if (!fail)
            {
                ans = x;
                break;
            }
            sorted.erase(sorted.find(x));
            x += n;
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
