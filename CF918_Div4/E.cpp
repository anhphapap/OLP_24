#include<bits/stdc++.h>

using namespace std;

int t,n,x;

bool check(vector<long long> a2, int l, int r, long long s){
    long long s1 = a2[r]-a2[l-1],s2=0,s3=0,s4=0;
    if(l-2>=0) s2 = a2[r] - a2[l-2];
    if(r-1>=0) s3 = a2[r-1] - a2[l-1];
    if(r-1>=0 && l-2>=0) s4 = a2[r-1] - a2[l-2];
    if(s1==s||s2==s||s3==s||s4==s) return true;
    return false;
}

void process(vector<long long> a1,vector<long long> a2){
    for(int i = 1; i<a1.size(); i++){
        for(int j = 1; j<=i; j++){
            if(check(a2,j,i,a1[i]-a1[j-1])) {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        vector<long long> a1,a2;
        a1.push_back(0);
        a2.push_back(0);
        for(int i = 1; i<=n;i++){
            cin>>x;
            if(i%2==1)
                a1.push_back(a1.back()+x);
            else
                a2.push_back(a2.back()+x);
        }
        process(a1,a2);
    }
    return 0;
}