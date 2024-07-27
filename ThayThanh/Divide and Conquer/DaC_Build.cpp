#include <bits/stdc++.h>

using namespace std;

int n = 8, counter = 0;
vector<vector<int>> a(8, vector<int>(8));

void fill(int x, int y, int l)
{
    counter++;
    switch (l)
    {
    case 1:
        a[x + 1][y] = a[x + 1][y + 1] = a[x][y + 1] = counter;
        break;
    case 2:
        a[x][y] = a[x + 1][y + 1] = a[x + 1][y] = counter;
        break;
    case 3:
        a[x + 1][y] = a[x][y] = a[x][y + 1] = counter;
        break;
    case 4:
        a[x][y + 1] = a[x + 1][y + 1] = a[x][y] = counter;
        break;
    }
}

void process(int x, int y, int l, int sz)
{
    if (sz == 2)
    {
        fill(x, y, l);
    }
    else
    {
        int nsz = sz / 2;
        switch (l)
        {
        case 1:
        {
            process(x, y + nsz, 4, nsz);
            process(x + nsz / 2, y + nsz / 2, 1, nsz);
            process(x + nsz, y, 2, nsz);
            process(x + nsz, y + nsz, 1, nsz);
            break;
        }
        case 2:
        {
            process(x, y, 3, nsz);
            process(x + nsz / 2, y + nsz / 2, 2, nsz);
            process(x + nsz, y, 2, nsz);
            process(x + nsz, y + nsz, 1, nsz);
            break;
        }
        case 3:
        {
            process(x, y, 3, nsz);
            process(x + nsz / 2, y + nsz / 2, 3, nsz);
            process(x + nsz, y, 2, nsz);
            process(x, y + nsz, 4, nsz);
            break;
        }
        case 4:
        {
            process(x, y, 3, nsz);
            process(x + nsz / 2, y + nsz / 2, 4, nsz);
            process(x, y + nsz, 4, nsz);
            process(x + nsz, y + nsz, 1, nsz);
            break;
        }
        }
    }
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    process(0, 0, 2, 8);
    output();
    return 0;
}
