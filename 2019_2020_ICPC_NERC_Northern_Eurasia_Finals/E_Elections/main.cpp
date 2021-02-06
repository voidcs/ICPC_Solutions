#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<ll> totalVotes(n, 0);
    vector<vector<ll>> v(m, vector<ll>(n+1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
            totalVotes[j] += v[i][j];
        }
        v[i][n] = i+1;
    }
    ll ans = INF;
    vector<ll> removed;
    ll curr = -1;
    //Sort each polling station based on the difference between 
    //candidate curr and candidate n-1
    //We should first remove stations where candidate n-1 won by the largest margin
    function<bool(vector<ll>, vector<ll>)> comp = [&](vector<ll> a, vector<ll> b){
        return (a[curr] - a[n-1]) < (b[curr] - b[n-1]);
    };
    for(int i = 0; i < n-1; i++){
        curr = i;
        ll x = totalVotes[i], y = totalVotes[n-1], cnt = 0;
        sort(v.begin(), v.end(), comp);
        vector<ll> id;
        for(int j = 0; j < m; j++){
            if(x >= y)
                break;
            cnt++;
            x -= v[j][i], y -= v[j][n-1];
            id.push_back(v[j][n]);
        }
        if(cnt < ans){
            ans = cnt;
            removed = id;
        }
    }
    cout<<ans<<endl;
    for(auto x: removed)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}