#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
array<ll, 2> dir[8] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    ll a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    vector<vector<ll>> dist(n, vector<ll>(m, INF));
    ll sx, sy;
    cin>>sx>>sy;
    sx--, sy--;
    dist[sx][sy] = a[sx][sy];
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({dist[sx][sy], sx, sy});
    while(!pq.empty()){
        ll depth = pq.top()[0];
        ll x = pq.top()[1];
        ll y = pq.top()[2];
        pq.pop();
        if(depth > dist[x][y])
            continue;
        function<bool(ll, ll)> valid = [&](ll x, ll y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        for(int i = 0; i < 8; i++){
            ll nx = x + dir[i][0];
            ll ny = y + dir[i][1];
            if(valid(nx, ny)){
                ll new_depth = max(a[nx][ny], depth);
                if(new_depth < dist[nx][ny]){
                    dist[nx][ny] = new_depth;
                    pq.push({new_depth, nx, ny});
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] < 0)
                ans += -dist[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}