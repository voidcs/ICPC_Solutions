#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n);
    vector<vector<int>> adj(n);
    vector<int> dp(n, -1);
    vector<int> in(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            x--;
            adj[x].push_back(i);
            in[i]++;
        }
    }
    
    function<int(int)> calc = [&](int u) {
        if (dp[u] != -1) 
            return dp[u];
        dp[u] = t[u];
        for(int c: adj[u]){
            dp[u] = max(dp[u], calc(c) + 1);
        }
        return dp[u];
    };
    
    int ans = 0;
    priority_queue<array<int, 2>> q;
    for(int i = 0; i < n; ++i) {
        calc(i);
        if (in[i] == 0) 
            q.push({dp[i], i});
    }
    
    int tim = 0;
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        ans = max(ans, p[0]+tim);
        tim++;
        for(int c: adj[p[1]]){
            in[c]--;
            if(in[c] == 0){
                q.push({dp[c], c});
            }
        }
    }
    cout << ans << endl;
}