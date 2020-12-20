#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin>>c;
            if(c == '1')
                v[i][j] = 1;
        }
    }
    
    vector<int> vis(n, 0);
    vector<int> ans;
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int i = 0; i < n; i++){
            if(v[u][i] == 0 || vis[i])
                continue;
            dfs(i);
        }
        ans.push_back(u);
    };
    
    dfs(0);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cout<<"impossible\n";
            return 0;
        }
    }
    for(int i = 0; i < n; i++)
        cout<<ans[i]<<" ";
    
    return 0;
}
