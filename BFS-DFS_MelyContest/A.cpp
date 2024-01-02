#include<bits/stdc++.h>

using namespace std;

struct Node{
    int x;
    string ans;
};

int a, b;

void dfs(){
    stack<Node> st;
    st.push({a,""});

    while(!st.empty()){
        Node temp = st.top();
        st.pop();

        if(temp.x == b){
            cout<<"YES"<<endl;
            cout<<temp.ans.length()+1<<endl;
            cout<<a<<" ";
            for(char c : temp.ans){
                int i = c - '0';
                if(i == 1) a*=2;
                else a = a*10+1;
                cout<<a<<" ";
            }
            exit(0);
        }else{
            if(temp.x*2<=b){
                st.push({temp.x*2,temp.ans+'1'});
            }
            if(temp.x*10+1<=b){
                st.push({temp.x*10+1,temp.ans+'2'});
            }
        }
    }
}

int main(){
    cin>>a>>b;
    dfs();
    cout<<"NO";
    return 0;
}