#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,c;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        if(a==b) cout<<c<<endl;
        else if(a==c) cout<<b<<endl;
        else cout<<a<<endl;
    }
    return 0;
}