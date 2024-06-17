/*
Có n thành phố đánh số từ 1 đến n, đường nối các thành phố (nếu có) là đường một chiều, mỗi đường đi có giá trị độ dài đường đi và chi phí phải trả khi đi trên đường đó. Tìm giải pháp giúp một người xuất phát từ thành phố 1 tìm đường đi ngắn nhất đến thành phố n, biết rằng người này chỉ có có tiền là k.
 Dữ liệu đầu vào trong tập tin roads.inp có cấu trúc:
 - Dòng đầu ghi k (0 ≤ k ≤ 10000).
 - Dòng 2 ghi n (2 ≤ n ≤ 100).
 - Dòng 3 ghi r con đường được nối.
 - r dòng tiếp theo, mỗi dòng ghi 4 số là s, e, l, t với ý nghĩa có đường nối từ đỉnh s đến đỉnh e, độ dài là l (1 ≤ l ≤ 100) và chi phí là t (0 ≤ t ≤ 100).
 Dữ liệu đầu ra ghi vào tập tin roads.out độ dài đường đi ngắn nhất từ thành phố 1 đến n, nếu không có ghi -1.
 Ví dụ
 roads.inp
 5
 6
 7
 1 2 2 3
 2 4 3 3
 3 4 2 4
 1 3 4 1
 4 6 2 1
 3 5 2 0
 5 4 3 2

 roads.out
 11
*/
#include <bits/stdc++.h>

using namespace std;

int k = 5, n = 6, r = 7;
vector<vector<pair<int, int>>> a(n + 1, vector<pair<int, int>>(n + 1, {0, 0}));
int bestWay = INT32_MAX;

void readData()
{
    int s, e, l, t;
    for (int i = 0; i < r; i++)
    {
        cin >> s >> e >> l >> t;
        a[s][e] = {l, t};
    }
}

void process(int idx, int len, int money)
{
    if (len > bestWay)
        return;
    for (int i = 1; i <= n; i++)
    {
        if (a[idx][i].first != 0 && money + a[idx][i].second <= k)
        {
            len += a[idx][i].first;
            money += a[idx][i].second;
            if (i == n && len < bestWay)
                bestWay = len;
            else
                process(idx + 1, len, money);
            len -= a[idx][i].first;
            money -= a[idx][i].second;
        }
    }
}

int main()
{
    readData();
    process(1, 0, 0);
    cout << bestWay;
    return 0;
}