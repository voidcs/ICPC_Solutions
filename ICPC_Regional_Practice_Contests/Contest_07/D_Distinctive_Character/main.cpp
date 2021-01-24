#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll m, n;
    cin>>m>>n;
    
    vector<ll> dist(1<<n, INF);
    queue<ll> q;
    while(m--){
        string s;
        cin>>s;
        ll x = 0;
        for(int i = 0; i < n; i++){
            x += (1<<i) * (s[i] == '1');
        }
        dist[x] = 0;
        q.push(x);
    }
    ll ans = 0;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        ans = u;
        for(int i = 0; i < n; i++){
            ll x = u^(1<<i);
            if(dist[x] > dist[u]+1){
                dist[x] = dist[u]+1;
                q.push(x);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(ans & (1<<i))
            cout<<"1";
        else
            cout<<"0";
    }
    
    
    return 0;
}