#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a = {
    {1, 2, 4, 9, 3, 2, 1, 4},
    {6, 9, 5, 4, 2, 3, 1, 4},
    {3, 6, 2, 3, 4, 1, 8, 3},
    {2, 3, 7, 3, 2, 1, 4, 2},
    {1, 2, 3, 2, 3, 9, 2, 1},
    {2, 1, 3, 4, 2, 4, 2, 8},
    {2, 1, 3, 2, 8, 4, 2, 1},
    {8, 2, 3, 4, 2, 3, 1, 2}};
vector<int> state(8), bestState;
int bestAns = -1, ans = 0;

bool canPutQueen(int row, int col)
{
    for (int i = 0; i < row; i++)
        if (abs(row - i) == abs(col - state[i]) || col == state[i])
            return false;
    return true;
}

int choose(int row)
{
    int maxCol = INT_MIN;
    int col = -1;
    for (int i = 0; i < 8; i++)
    {
        if (canPutQueen(row, i) && a[row][i] > maxCol)
        {
            maxCol = a[row][i];
            col = i;
        }
    }
    return col;
}

void process(int idx)
{
    int j = choose(idx);
    if (j == -1)
        return;
    state[idx] = j;
    ans += a[idx][j];
    if (idx == 7 && ans > bestAns)
    {
        bestAns = ans;
        bestState = state;
    }
    else
        process(idx + 1);
    ans -= a[idx][state[idx]];
}

void output()
{
    for (int i : bestState)
        cout << i << " ";
    cout << endl
         << bestAns;
}

int main()
{
    process(0);
    output();
    return 0;
}