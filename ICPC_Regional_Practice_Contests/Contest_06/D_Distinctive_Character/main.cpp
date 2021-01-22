#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main() {
    ll n, k;
    cin>>n>>k;
    vector<ll> dist(1<<k, INF);
    queue<ll> q;
    while(n--){
        string s;
        cin>>s;
        ll x = 0;
        for(int i = 0; i < k; i++)
            x += (1<<i) * (s[i]-'0');
        dist[x] = 0;
        q.push(x);
    }
    ll ans = 0;
    while(!q.empty()){
        ll u = q.front();
        ans = u;
        q.pop();
        for(int i = 0; i < k; i++){
            ll v = u^(1<<i);
            if(dist[u]+1 < dist[v]){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    for(int i = 0; i < k; i++){
        if(ans & (1<<i))
            cout<<"1";
        else
            cout<<"0";
    }
    return 0;
}
