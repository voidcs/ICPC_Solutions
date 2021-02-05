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
        ll n, m, k;
        cin>>n>>m>>k;
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
        
        while(m--){
            ll a, b, c;
            cin>>a>>b>>c;
            pq.push({c, a, b});
        }
        multiset<ll> MST;
        vector<ll> par(n+1);
        iota(par.begin(), par.end(), 0);
        
        function<ll(ll)> find = [&](ll x){
            return (x == par[x]) ? x : par[x] = find(par[x]);
        };
        
        function<void(ll, ll, ll)> unite = [&](ll x, ll y, ll s){
            x = find(x), y = find(y);
            if(x != y){
                par[x] = y;
            }
        };
        bool MST_All_Smaller = 0;
        ll ans = 0;
        while(!pq.empty()){
            ll s = pq.top()[0];
            ll a = pq.top()[1], b = pq.top()[2];
            pq.pop();
            
            if(find(a) != find(b)){
                MST.insert(s);
                unite(a, b, s);
            }
            ll last = *(--MST.end());
            //If our highest speed limit is less than k and we have our MST already
            //we can possibly find a better answer above k
            if(MST.size() >= n-1 && last < k && abs(k-s) <= abs(k-last)){
                MST_All_Smaller = 1;
                MST.insert(s);
                ans = min(k-last, abs(s-k));
            }
        }
        
        if(MST_All_Smaller){
            cout<<ans<<endl;
        }
        else{
            ans = 0;
            for(auto x: MST){
                if(x > k)
                    ans += x-k;
            }
            cout<<ans<<endl;
        }
    }
    
    return 0;
}