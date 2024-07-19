#include <bits/stdc++.h>

using namespace std;

char c[4][4];
vector<bool> mark(17, false);
int b = 0, w = 0;
int fx[5] = {0, -1, 1, 0, 0};
int fy[5] = {0, 0, 0, 1, -1};
int counter = 0, best = INT_MAX;

void change(int idx)
{
    idx--;
    int x = idx / 4;
    int y = idx % 4;
    for (int i = 0; i < 5; i++)
    {
        int X = x + fx[i];
        int Y = y + fy[i];
        if (X >= 0 && X < 4 && Y >= 0 && Y < 4)
        {
            if (c[X][Y] == 'b')
            {
                b--;
                w++;
                c[X][Y] = 'w';
            }
            else
            {
                b++;
                w--;
                c[X][Y] = 'b';
            }
        }
    }
}

bool check(){
    for(int i = 1; i <= 16; i++){
        if(!mark[i]){
            
        }
    }
}

void processb()
{
    if (counter > best)
        return;
    for (int i = 1; i <= 16; i++)
    {
        if (!mark[i])
        {
            counter++;
            cout << counter << endl;
            mark[i] = true;
            change(i);
            if (b == 16 || w == 16)
            {
                if (counter < best)
                    best = counter;
            }
            else
                processb();
            change(i);
            mark[i] = false;
            counter--;
        }
    }
}

int main()
{
    for (auto &x : c)
        for (auto &y : x)
        {
            cin >> y;
            if (y == 'b')
                b++;
            else
                w++;
        }
    change(6);
    for (auto &x : c)
    {
        for (auto &y : x)
            cout << y;
        cout << endl;
    }
    // processb();
    if (best == INT_MAX)
        cout << "Impossible";
    else
        cout << best;
    return 0;
}