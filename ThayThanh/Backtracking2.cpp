#include<bits/stdc++.h>

using namespace std;

int n = 8;
vector<int> state(n,0);

bool canPutQueen(int idx, int i){
    for(int j = 0; j < idx; j++){
        if(i == state[j] || abs(i - state[j]) == abs(idx - j)) return false;
    }
    return true;
}

void output(){
    for(int x : state) cout << x <<" ";
    cout<<endl;
}

void process(int idx){
    if(idx > 7){
        output();
        return;
    }
    for(int i = 0; i < n; i++){
        if(canPutQueen(idx,i)){
            state[idx] = i;
            process(idx+1);
        }
    }
} 



int main(){
    process(0);
    output();
    return 0;
}