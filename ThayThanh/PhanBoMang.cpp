#include <bits/stdc++.h>

using namespace std;

int n = 5, k = 3;
vector<int> a = {1, 4, 6, 9, 10};
vector<int> sumArr(k, 0);
vector<vector<int>> group(k, vector<int>());
int sum = accumulate(a.begin(), a.end(), 0);
int target;

bool process(int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < k; i++)
            if (sumArr[i] != target)
                return false;
        return true;
    }
    for (int i = 0; i < k; i++)
    {
        if (sumArr[i] + a[idx] <= target)
        {
            sumArr[i] += a[idx];
            group[i].push_back(a[idx]);
            if (process(idx + 1))
                return true;
            sumArr[i] -= a[idx];
            group[i].pop_back();
        }
    }
    return false;
}

int main()
{
    if (sum % k == 0)
    {
        sort(a.begin(),a.end());
        target = sum / k;
        if (process(0))
        {
            for (int i = 0; i < k; i++)
            {
                for (int x : group[i])
                    cout << x << " ";
                cout << endl;
            }
        }
        else
        {
            cout << "Khong hop le!";
        }
    }
    else
    {
        cout << "Khong hop le!";
    }
    return 0;
}