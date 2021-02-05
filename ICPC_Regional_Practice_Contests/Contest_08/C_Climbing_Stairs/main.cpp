#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, r, k;
    cin>>n>>r>>k;
    ll ans = 0;
    if(k > r){
        ans = 2*k-r;
        ans = max(ans, n);
        if(2*k-r < n && (n%2 != (2*k-r)%2))
            ans++;
        ans += r;
    }
    else{
        ans = max(r, n);
        if(r%2 != n%2 && n > r)
            ans++;
        ans += r;
    }
    cout<<ans<<endl;
    return 0;
}