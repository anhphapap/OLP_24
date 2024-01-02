#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, s;
    cin >> n;
    string a;
    while (n--)
    {
        m = 3;
        s = 198;
        while (m--)
        {
            cin >> a ;
            if(a[0]=='?'){
                s-=int(a[1])+int(a[2]);
                cout<<char(s)<<endl;
            }else if(a[1]=='?'){
                s-=int(a[0])+int(a[2]);
                cout<<char(s)<<endl;
            }else if(a[2]=='?'){
                s-=int(a[0])+int(a[1]);
                cout<<char(s)<<endl;
            }
        }
    }
    return 0;
}