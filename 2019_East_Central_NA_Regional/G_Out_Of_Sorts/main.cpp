#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, m, a, c, x0;
    cin>>n>>m>>a>>c>>x0;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        ll next = (x0*a)+c;
        next %= m;
        x0 = next;
        v.push_back(next);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll l = 0, r = n-1;
        bool found = 0;
        while(l <= r){
            ll mid = (l+r)/2;
            if(v[mid] == v[i]){
                found = 1;
                break;
            }
            else if(v[mid] < v[i]){
                l = mid+1;
            }
            else
                r = mid-1;
        }
        if(found)
            ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}