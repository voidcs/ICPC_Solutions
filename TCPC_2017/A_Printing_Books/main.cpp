#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, x;
        cin>>n>>x;
        ll l = 0, r = 1e15;
        ll ans = -1;
        while(l <= r){
            ll mid = (l+r)/2;
            ll used = 0;
            ll p = 1, cnt = 0;
            while(p <= x){
                p *= 10;
                cnt++;
            }
            ll q = p/10;
            ll d = p - x;
            //cout<<"p: "<<p<<"  d: "<<d<<"   mid: "<<mid<<endl;
            ll t = mid;
            ll len = to_string(x).length();
            while(d || t){
                //cout<<"len: "<<len<<"   d: "<<d<<"   t: "<<t<<"   used: "<<used<<endl;
                if(t <= d){
                    used += (len * t);
                    break;
                }
                t -= d;
                used += (len) * d;
                len++;
                p *= 10;
                q *= 10;
                d = p - q;
            }
            //cout<<"mid: "<<mid<<"   used: "<<used<<endl<<endl;
            if(used == n){
                ans = mid;
                break;
            }   
            else if(used > n)
                r = mid-1;
            else
                l = mid+1;
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}