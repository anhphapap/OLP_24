#include<bits/stdc++.h>

using namespace std;

const int MAX=1005;
int n, fIdx[MAX], len = -1, ans=-1, prefixSum[1000006], a[1000006];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("exlist.inp","r",stdin);
    freopen("exlist.out","w",stdout);
    cin>>n;
    prefixSum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prefixSum[i] = prefixSum[i-1]+a[i];
        if(fIdx[a[i]]==0) fIdx[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int l = i-fIdx[a[i]]+1;
        if(l>len){
            len=l;
            ans=prefixSum[i]-prefixSum[fIdx[a[i]]-1];
        }else if(len == l && ans<prefixSum[i]-prefixSum[fIdx[a[i]]-1]){
            ans=prefixSum[i]-prefixSum[fIdx[a[i]]-1];
        }
    }
    cout<<len<<" "<<ans;
    return 0;
}