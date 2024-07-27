#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a(8, vector<int>(8, 0));
int goX[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int goY[8] = {1, -1, 2, 2, 1, -1, -2, -2};

void output()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    if(getchar()=='y'){
        cin.ignore();
        cout<<"========"<<endl;
    }
}

void process(int n, int m, int idx)
{
    for (int i = 0; i < 8; i++)
    {
        int x = n + goX[i];
        int y = m + goY[i];
        if (x >= 0 && x < 8 && y >= 0 && y < 8 && a[x][y] == 0)
        {
            a[x][y] = idx;

            if (idx == 64){
                output();
                return;
            }
            else
                process(x, y, idx + 1);

            a[x][y] = 0;
        }
    }
}

int main()
{
    a[0][0] = 1;
    process(0, 0, 2);
    output();
    return 0;
}