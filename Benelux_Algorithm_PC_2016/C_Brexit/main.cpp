#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m, x, L;
    cin>>n>>m>>x>>L;
    x--, L--;
    vector<ll> deg(n, 0), vis(n, 0);
    vector<vector<ll>> adj(n);
    while(m--){
        ll a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    if(x == L){
        cout<<"leave\n";
        return 0;
    }
    vector<ll> need(n);
    for(int i = 0; i < n; i++){
        need[i] = adj[i].size();
    }
    
    queue<ll> q;
    q.push(L);
    vis[L] = 1;
    while(!q.empty()){
        ll u = q.front();
        vis[u] = 1;
        q.pop();
        for(int c: adj[u]){
            deg[c]--;
            if(need[c]-deg[c] >= (need[c]+1)/2 && !vis[c]){
                vis[c] = 1;
                q.push(c);
            }
        }
    }
    if(deg[x] <= need[x]/2)
        cout<<"leave\n";
    else
        cout<<"stay\n";
    return 0;
}