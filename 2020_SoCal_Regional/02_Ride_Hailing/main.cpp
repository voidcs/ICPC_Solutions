#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 998244353;

int main(){
    freopen("input.txt", "r", stdin);
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    map<ll, ll> avail;
    for(int i = 0; i < q; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        pq.push({c, a, b});
    }
    ll ans = 0;
    while(!pq.empty()){
        ll t = pq.top()[0];
        ll u = pq.top()[1];
        ll v = pq.top()[2];
        pq.pop();
        array<ll, 2> best = {INF, INF};
        ll time = INF;
        cout<<"t: "<<t<<"  u: "<<u<<"  v: "<<v<<endl;
        cout<<"available: \n";
        for(auto x: avail){
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<endl;
        for(auto x: avail){
            ll newTime = x.second + dist[x.first][u];
            if(newTime <= t){
                if(newTime < time){
                    time = newTime;
                    best = {x.first, x.second};
                }
            }
        }
        if(time == INF){
            ans++;
            if(!avail.count(v)){
                avail[v] = t + dist[u][v];
            }
            else{
                if(t + dist[u][v] < avail[v])
                    avail[v] = t + dist[u][v];
            }
        }
        else{
            cout<<"best: "<<best[0]<<endl;
            avail.erase(best[0]);
            if(!avail.count(v)){
                avail[v] = time + dist[u][v];
            }
            else{
                if(time + dist[u][v] < avail[v])
                    avail[v] = time + dist[u][v];
            }
        }
        cout<<"after: \n";
        for(auto x: avail){
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    
    return 0;
}