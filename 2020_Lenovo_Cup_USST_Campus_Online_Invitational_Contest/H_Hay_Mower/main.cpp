#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 998244353;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k;
    cin>>n>>m>>k;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> t(n, vector<ll>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            a[i][j] %= mod;
        }
    }
    ll ans = 0;
    vector<array<ll, 3>> q;
    while(k--){
        char x;
        ll y, z;
        cin>>x>>y>>z;
        if(x == 'r')
            q.push_back({z, y-1, 1});
        else
            q.push_back({z, y-1, 2});
    }
    
    sort(q.begin(), q.end());
    for(int i = 0; i < q.size(); i++){
        ll index = q[i][1], time = q[i][0];
        time %= mod;
        if(q[i][2] == 2){
            for(int j = 0; j < n; j++){
                ans = (ans + ((time - t[j][index]+mod)%mod * a[j][index]) % mod);
                t[j][index] = time;
            }
        }
        else{
            for(int j = 0; j < m; j++){
                ans = (ans + ((time - t[index][j]+mod)%mod * a[index][j]) % mod);
                t[index][j] = time;
            }
        }
        ans %= mod;
    }
    cout<<ans<<endl;
    
    
    return 0;
}