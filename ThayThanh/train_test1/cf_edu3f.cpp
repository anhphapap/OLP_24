#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 2 * 1e5 + 1;
const int MAX = 1e9 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    vector<int> stt;
    pair<int, int> ans[MAXN];
    for (auto &x : a)
    {
        cin >> x.first >> x.second;
        stt.push_back(x.first);
        ans[x.first].first = 0;
        ans[x.first].second = x.second;
    }
    for (auto &x : b)
        cin >> x.first >> x.second;
    sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y)
         { return x.first < y.first; });
    sort(b.begin(), b.end(), [&](pair<int, int> x, pair<int, int> y)
         { return x.first < y.first; });
    for (auto &x : a)
    {
        while (true)
        {
            int low = 0, high = b.size() - 1;
            while (low < high)
            {
                int mid = low + (high - low + 1) / 2;
                if (b[mid].first > x.first + x.second)
                    high = mid - 1;
                else
                    low = mid;
            }
            if (low < 0 || low >= b.size() || b[low].first > x.first + x.second || b[low].first < x.first)
                break;
            vector<int> tmp;
            for (int i = low; b[i].first >= x.first && i >= 0; i--)
            {
                ans[x.first].first++;
                ans[x.first].second += b[i].second;
                x.second += b[i].second;
                tmp.push_back(i);
            }
            for (int x : tmp)
                b.erase(b.begin() + x);
        }
    }
    for (int x : stt)
        cout << ans[x].first << " " << ans[x].second << endl;
    return 0;
}