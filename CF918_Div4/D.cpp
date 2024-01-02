#include<bits/stdc++.h>

using namespace std;

int t,n,m;
string s, ans;

int check(int i){
    if((s[i+2]=='b'||s[i+2]=='c'||s[i+2]=='d')&&(s[i+3]=='b'||s[i+3]=='c'||s[i+3]=='d'||i+3==n))
        return 3;
    else
        return 2;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        ans="";
        for(int i = 0; i < n; i+=m){
            m=check(i);
            ans+=s.substr(i,m)+'.';
        }
        ans=ans.substr(0,ans.length()-1);
        cout<<ans<<endl;
    }
    return 0;
}