#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll ans = 0;
        map<array<ll, 2>, ll> m;
        ll n;
        cin>>n;
        while(n--){
            ll x, y, u, v;
            cin>>x>>y>>u>>v;
            //Subtract point from looking direction vector
            u -= x;
            v -= y;
            //If one of the values is zero, set other value to 1 or -1
            //I.E. (0, 5) -> (0, 1)    (-5, 0) -> (-1, 0)
            if(u == 0 || v == 0){
                if(v)
                    v /= abs(v);
                if(u)
                    u /= abs(u);
            }
            //Otherwise create normalized vector by dividing by gcd(u, v)
            else{
                ll g = __gcd(abs(u), abs(v));
                u /= g, v /= g;
            }
            if(m.count({-u, -v}))
                ans += m[{-u, -v}];
            m[{u, v}]++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}