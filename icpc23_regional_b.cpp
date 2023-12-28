#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main(){
    int t,n,m,x;
    bool res;
    ifstream fi("icpc23_regional_b.txt");
    fi>>t;
    while(t--){
        res=true;
        fi>>n>>m;
        vector<bool> a(m,0);
        for(int i = 0; i<n; i++){
            int solAll=0;
            for(int j = 0; j<m; j++){
                fi>>x;
                if(x == 1){
                    a[j] = true;
                    solAll++;
                }
            }
            if(solAll == m || solAll == 0) res = false;
        }
        for(int i = 0; i<m; i++) if(a[i]==false) res = false;
        if(res == false) cout<<"NO\n";
        else cout<<"YES\n";
        a.clear();
    }
    fi.close();
    return 0;
}