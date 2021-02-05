#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin>>q;
    while(q--){
        ll n, m, a, b;
        cin>>n>>m>>a>>b;
        vector<ll> t(m);
        ll time, robber;
        //Time is how far the guard is to the endpoint
        //Robber is how far the robber is to the endpoint
        if(a < b){
            time = b-1;
            robber = a-1;
        }
        else{
            time = n-b;
            robber = n-a;
        }
        
        for(int i = 0; i < m; i++)
            cin>>t[i];
        sort(t.begin(), t.end());
        
        function<bool(ll)> valid = [&](ll mid){
            //If we are trying to place more bombs than the distance between us
            //Then the answer is obviously false
            if(mid >= abs(time-robber))
                return false;
            ll guard = time;
            for(int i = mid-1; i >= 0; i--){
                //If the time of this bomb takes longer than the guard will 
                //reach the endpoint, then this bomb will not finish
                if(t[i] >= guard)
                    return false;
                guard--;
            }
            return true;
        };
        ll l = 0, r = m;
        ll ans = 0;
        while(l <= r){
            ll mid = (l+r)/2;
            if(valid(mid)){
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}