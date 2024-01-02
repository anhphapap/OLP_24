#include<bits/stdc++.h>

using namespace std;

int tc,n,m;
vector<vector<int>> a;
vector<vector<bool>> mark;
int goX[4] = {-1,1,0,0};
int goY[4] = {0,0,-1,1};

bool check(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && mark[x][y]==0;
}

int bfs(int X, int Y){
    int ans=0;
    queue<pair<int,int>> q;
    q.push({X,Y});
    mark[X][Y]=true;
    ans+=a[X][Y];

    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            X = temp.first + goX[i];
            Y = temp.second + goY[i];
            if(check(X,Y)){
                q.push({X,Y});
                mark[X][Y]=true;
                ans+=a[X][Y];
            }
        }
    }
    return ans;
}

int main(){
    cin>>tc;
    while(tc--){
        int res = 0;
        cin>>n>>m;
        a.resize(n,vector<int>(m));
        mark.resize(n,vector<bool>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>a[i][j];
                mark[i][j] = (a[i][j] == 0) ? 1 : 0;
            }
        }
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(mark[i][j] == 0){
                    int temp = bfs(i,j);
                    if(temp>res) res = temp;
                }
            }
        }
        cout<<res<<endl;
        mark.clear();
        a.clear();
    }
    return 0;
}
