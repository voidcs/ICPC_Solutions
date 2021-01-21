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
    set<array<ll, 3>> s;
    vector<vector<ll>> v(n, vector<ll>(m, INF));
    v[x][y] = a[x][y];
    s.insert({a[x][y], x, y});
    ll ans = 0;
    while(!s.empty()){
        ll row = (*s.begin())[1];
        ll col = (*s.begin())[2];
        ll depth = (*s.begin())[0];
        s.erase(s.begin());
        if(depth < 0)
            ans += -depth;
        function<bool(ll, ll)> valid = [&](ll x, ll y){
            return (x >= 0 && x < n && y >= 0 && y < m);
        };
        for(int i = 0; i < 8; i++){
            ll nx = row+dir[i][0];
            ll ny = col+dir[i][1];
            if(valid(nx, ny)){
                ll new_depth = max(depth, a[nx][ny]);
                if(new_depth < v[nx][ny]){
                    s.erase({v[nx][ny], nx, ny});
                    v[nx][ny] = new_depth;
                    s.insert({v[nx][ny], nx, ny});
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
