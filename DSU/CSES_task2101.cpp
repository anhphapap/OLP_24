#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct union_find{
    vector<int> data;

    union_find(int n = -1){
        if(n > 0)
            init(n);
    }

    void init(int n){
        data.assign(n+1,-1);
    }

    int find(int x){
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y) return false;

        if(x < y) swap(x,y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m;
    vector<pair<int,int>> edge(m);
    vector<pair<int,int>> query(q);
    for(auto &x : edge) cin>>x.first>>x.second;
    for(auto &x : query) cin>>x.first>>x.second;

    return 0;
}