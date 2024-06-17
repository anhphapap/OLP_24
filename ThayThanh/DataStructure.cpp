#include<bits/stdc++.h>

using namespace std;

void output(vector<int> a){
    for(auto x : a) cout<<x<<"\t";
    cout<<endl;
}

int main(){
    vector<int> a= {5,7,1,9,3,8};

    output(a);

    sort(a.begin(), a.end(), [](int a, int b){return a>b;});

    output(a);

    int r = count_if(a.begin(), a.end(), [](auto x){return x % 2 == 0;});
    cout<<r<<endl;
    
    return 0;
}