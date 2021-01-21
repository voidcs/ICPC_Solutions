#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
array<ll, 2> dir[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main(){
    ll n, m;
    cin>>n>>m;
    ll a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    ll x, y;
    cin>>x>>y;
    x--, y--;
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    vector<vector<ll>> v(n, vector<ll>(m, INF));
    v[x][y] = a[x][y];
    pq.push({a[x][y], x, y});
    ll ans = 0;
    while(!pq.empty()){
        ll row = pq.top()[1];
        ll col = pq.top()[2];
        ll depth = pq.top()[0];
        pq.pop();
        if(depth > v[row][col]){
            continue;
        }
        function<bool(ll, ll)> valid = [&](ll x, ll y){
            return (x >= 0 && x < n && y >= 0 && y < m);
        };
        for(int i = 0; i < 8; i++){
            ll nx = row+dir[i][0];
            ll ny = col+dir[i][1];
            if(valid(nx, ny)){
                ll new_depth = max(depth, a[nx][ny]);
                if(new_depth < v[nx][ny]){
                    v[nx][ny] = new_depth;
                    pq.push({v[nx][ny], nx, ny});
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] < 0)
                ans += -v[i][j];
        }
    }
    cout<<ans<<endl;
    return 0;
}
