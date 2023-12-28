#include<bits/stdc++.h>

using namespace std;

int n,m,ans=0;
vector<vector<int>> e;
vector<int> a;
vector<bool> mark;

void dfs(int start){
    int minC = a[start];
    stack<int> q;
    q.push(start);
    mark[start] = 1;
    ans -= a[start];

    while(!q.empty()){
        int temp = q.top();
        q.pop();

        for(int x : e[temp]){
            if(!mark[x]){
                q.push(x);
                ans-=a[x];
                minC = (minC>a[x]) ? a[x] : minC;
                mark[x] = 1;
            }
        }
    }
    ans+= minC;
}

int main(){
    cin>>n>>m;
    a.resize(n);
    e.resize(n);
    mark.resize(n,1);
    for(int i=0; i<n; i++) 
    {
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=0; i<m; i++){
        int x,y; 
        cin>>x>>y;
        x--;
        y--;
        mark[x]=0;
        mark[y]=0;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i = 0; i<n; i++) if(!mark[i]) dfs(i);
    cout<<ans;
    return 0;
}