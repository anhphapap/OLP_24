#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        for (int i = 0; i < 5; i++)
            *min_element(a.begin(), a.end())+=1;
        cout<<a[0]*a[1]*a[2]<<endl;
    }
    return 0;
}