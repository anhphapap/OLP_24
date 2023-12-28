#include<bits/stdc++.h>
#define MAX 100007
using namespace std;

int n,q,a[MAX];
long long BIT[MAX];

long long get(int x){
    long long s = 0;
    while(x>0){
        s+=BIT[x];
        x -= x&-x;
    }
    return s;
}

void update(int x, int val){
    while(x<=n){
        BIT[x] += val;
        x += x&-x;
    }
}

void updateRange(int u,int v, int val){
    update(u, val);
    update(v+1,-val);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        update(i, a[i]);
    }
    while(q--){
        int t,u,v,z;
        cin>>t>>u>>v;
        if(t == 1){
            cin>>z;
            updateRange(u,v,z);
        }else{
            cout<<get(v)-get(u-1)<<endl;
        }
    }
    return 0;
}