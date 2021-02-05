#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a[4];
        for(int i = 0; i < 4; i++)
            cin>>a[i];
        sort(a, a + 4);
        cout<<a[0]*a[2]<<endl;
    }
    return 0;
}