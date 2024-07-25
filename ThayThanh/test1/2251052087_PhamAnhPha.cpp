#include <bits/stdc++.h>

#define ll long long

using namespace std;

ifstream fi("pacman.inp");
ofstream fo("pacman.out");

int n, m;
vector<vector<char>> a;
vector<vector<bool>> mark;
// vector<pair<int, int>> ans, bestAns;
int goX[4] = {-1, 1, 0, 0};
int goY[4] = {0, 0, 1, -1};
int step = 0, bestStep = INT_MAX;
pair<int, int> s, e;

bool check(int X, int Y)
{
    return X >= 0 && X < n - 1 && Y >= 0 && Y < m - 1 && !mark[X][Y] && a[X][Y] != '*';
}

void process()
{
    if (step > bestStep)
        return;

    for (int i = 0; i < 4; i++)
    {
        int X = s.first + goX[i];
        int Y = s.second + goY[i];
        if (check(X, Y))
        {
            // ans.push_back({X, Y});
            step++;
            mark[X][Y] = true;
            s = {X, Y};
            if (s == e && step - 1 < bestStep)
            {
                // bestAns = ans;
                bestStep = step - 1;
            }
            else
                process();
            s = {X - goX[i], Y - goY[i]};
            mark[X][Y] = false;
            step--;
            // ans.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fi >> n >> m >> s.first >> s.second >> e.first >> e.second;
    a.resize(n, vector<char>(m));
    mark.resize(n, vector<bool>(m, false));
    mark[s.first][s.second] = true;
    for (auto &x : a)
        for (auto &y : x)
            fi >> y;
    process();
    fo << (bestStep == INT_MAX ? -1 : bestStep) << endl;
    // for (auto x : bestAns) cout << x.first << " " << x.second << endl;
    fi.close();
    fo.close();
    return 0;
}