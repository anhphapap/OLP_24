// https://leetcode.com/problems/sudoku-solver/

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

int n = 9;

bool check(int x, int y, char z)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == z)
            return false;

        if (board[i][y] == z)
            return false;

        if (board[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3] == z)
            return false;
    }

    return true;
}

bool process()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                for (char k = '1'; k <= '9'; k++)
                {
                    if (check(i, j, k))
                    {
                        board[i][j] = k;
                        if (process() == true)
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    process();
    for (auto x : board)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << endl;
    }
    return 0;
}