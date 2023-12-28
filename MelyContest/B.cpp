#include<bits/stdc++.h>

using namespace std;

struct Node{
    int x,y;
    string ans;
};

string a,b;
string step[8]={"L","R","U","D","LU","LD","RU","RD"};
pair<int, int> start,goal;
int goX[8]={0,0,-1,1,-1,1,-1,1};
int goY[8]={-1,1,0,0,-1,-1,1,1};
vector<vector<bool>> mark(8,vector<bool>(8,0));

bool check(int X, int Y){
    return X >= 0 && X < 8 && Y >= 0 && Y < 8 && mark[X][Y]==0;
}

void bfs(){
    queue<Node> q;
    q.push({start.first,start.second,""});
    mark[start.first][start.second] = true;

    while(!q.empty()){
        Node temp = q.front();
        q.pop();

        if(temp.x == goal.first && temp.y == goal.second){
            cout<<temp.ans.length()<<endl;
            for(int i = 0; i<temp.ans.length(); i++){
                int j = temp.ans[i] - '0';
                cout<<step[j]<<endl;
            }
            return;
        }else{
            for(int i = 0; i<8; i++){
                int X=temp.x+goX[i], Y=temp.y+goY[i];
                if(check(X,Y)){
                    char c = '0' + i;
                    q.push({X,Y,temp.ans+c});
                    mark[X][Y]=1;
                }
            }
        }
    }
}


int main(){
    cin>>a>>b;
    start.first = 8 - (a[1] - '0');
    start.second = a[0] - 'a';
    goal.first = 8 - (b[1] - '0');
    goal.second = b[0] - 'a';
    bfs();
    return 0;
}