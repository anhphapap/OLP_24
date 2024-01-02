#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,m,s,a,t;
    cin>>n;
    while(n--){
        cin>>m;
        s=0;
        while(m--){
            cin>>a;
            s+=a;
        }
        t=sqrt(s);
        if(t*t==s){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}