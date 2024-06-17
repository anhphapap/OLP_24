#include <bits/stdc++.h>

using namespace std;

int n = 5, k = 3;
vector<int> state(k, 0);
vector<bool> mark(n + 1, 0);

void process1(int idx)
{
    {
        for (int i = 1; i <= n; i++)
        {
            if (mark[i] == 0)
            {
                mark[i] = 1;
                state[idx] = i;
                if (idx == n - 1)
                {
                    for (int x : state)
                        cout << x << " ";
                    cout << endl;
                }
                else
                    process1(idx + 1);
                mark[i] = 0;
            }
        }
    }
}

void process2(int idx)
{
    for (int i = 1; i <= n; i++)
    {
        state[idx] = i;
        if (idx == k - 1)
        {
            for (int x : state)
                cout << x << " ";
            cout << endl;
        }
        else
            process2(idx + 1);
    }
}

void process3(int idx){
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0){
            mark[i] = 1;
            state[idx] = i;
            if(idx == k-1){
                for(int x : state) cout<<x<<" ";
                cout<<endl;
            }else{
                process3(idx + 1);
            }
            mark[i] = 0;
        }
    }
}

int main()
{
    // process1(0);
    //process2(0);
    process3(0);
    return 0;
}