#include<bits/stdc++.h>
#define maxn 60007
using namespace std;

int n, a[maxn];
long long BIT[maxn],sum=0;

long long get(int x){
    long long s = 0;
    while(x<=n){
        s+=BIT[x];
        x += x&-x;
    }
    return s;
}

void update(int x, int val){
    while(x>0){
        BIT[x] += val;
        x -= x&-x;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        update(a[i],1);
        sum += get(a[i]+1);
    }    
    cout<<sum;
    return 0;
}