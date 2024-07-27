#include <bits/stdc++.h>

using namespace std;

int sum[31];
int n;

void output(int idx)
{
    cout << "n = ";
    for (int i = 1; i < idx; i++)
        cout << sum[i] << " + ";
    cout << sum[idx] << endl;
}

void process(int x, int idx)
{
    for (int i = 1; i <= n; i++)
    {
        if (x >= 0 && sum[idx - 1] <= i)
        {
            x -= i;
            sum[idx] = i;
            if (x == 0)
                output(idx);
            else
            {
                process(x, idx + 1);
                x += i;
            }
        }
    }
}

int main()
{
    sum[0] = 1;
    cin >> n;
    process(n, 1);
    return 0;
}