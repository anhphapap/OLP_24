#include <bits/stdc++.h>

using namespace std;

struct union_find
{
    vector<int> data;
    int components;

    union_find(int n = -1)
    {
        if (n > 0)
            init(n);
    }

    void init(int n)
    {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x)
    {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x)
    {
        return -data[find(x)];
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
}

int
main()
{

    return 0;
}