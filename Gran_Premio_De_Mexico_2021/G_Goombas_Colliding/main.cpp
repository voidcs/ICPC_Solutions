#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;
    ll ans = 0;
    for(int i = 0; i < m; i++){
        ll p, d;
        cin>>p>>d;
        if(d)
            ans = max(ans, n-p);
        else
            ans = max(ans, p);
    }
    cout<<ans<<endl;
    return 0;
}
