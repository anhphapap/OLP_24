#include<bits/stdc++.h>

using namespace std;

const int MAX = 10e6 + 7;
int n,k,x;
int mark[MAX], a[MAX];

int main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin >> x;
        a[x]=i;
    }
    return 0;
}