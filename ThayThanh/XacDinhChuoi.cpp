#include <bits/stdc++.h>

using namespace std;

int n;
char s[21];
string z = "AB";

void output()
{
    for (int i = 1; i <= n; i++)
        cout << s[i];
    cout << endl;
}

void process(int idx)
{

    for (int i = 0; i < z.length(); i++)
    {
        s[idx] = z[i];
        if (s[idx - 1] == 'B' && i == 1)
            continue;
        if (idx == n)
            output();
        else
            process(idx + 1);
    }
}

int main()
{
    cin >> n;
    s[0] = 'A';
    process(1);
    return 0;
}