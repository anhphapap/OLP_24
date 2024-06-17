#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
int goX[4]={0,0,-1,1};
int goY[4]={1,-1,0,0};

bool check(int x, int y){
    int tempX,tempY;
    for(int i =0;i<4;i++){
        tempX=x+goX[i];
        tempY=y+goY[i];
        if(tempX>=0&&tempX<x&&tempY>=0&&tempY<y){
            if(a[tempX][tempY]==0) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    return 0;
}