#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll c[3];
        for(int i = 0; i < 3; i++)
            cin>>c[i];
        ll a[5];
        for(int i = 0; i < 5; i++)
            cin>>a[i];
        for(int i = 0; i < 3; i++)
            c[i] -= a[i];
        bool flag = 0;
        for(int i = 0; i < 3; i++){
            if(c[i] < 0)
                flag = 1;
        }
        if(flag){
            cout<<"NO\n";
            continue;
        }
        a[3] -= c[0];
        a[4] -= c[1];
        ll r = max(0LL, a[3]) + max(0LL, a[4]);
        if(r <= c[2])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}