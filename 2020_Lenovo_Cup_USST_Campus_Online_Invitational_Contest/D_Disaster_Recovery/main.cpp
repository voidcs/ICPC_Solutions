#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<int> par(n+1);
    vector<array<int, 2>> v;
    vector<int> deg(n+1, 0);
    iota(par.begin(), par.end(), 0);
    while(m--){
        int a, b;
        cin>>a>>b;
        if(a < b)
            swap(a, b);
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    function<int(int)> find = [&](int x){
        return (x == par[x]) ? x : par[x] = find(par[x]);
    };
    function<void(int, int)> unite = [&](int x, int y){
        x = find(x), y = find(y);
        if(x != y)
            par[x] = y;
    };
    
    for(auto x: v){
        if(find(x[0]) != find(x[1])){
            deg[x[0]]++, deg[x[1]]++;
            unite(x[0], x[1]);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, deg[i]);
    cout<<ans<<endl;
    
    return 0;
}