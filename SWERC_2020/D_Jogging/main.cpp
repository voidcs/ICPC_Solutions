#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m, l, r;
    cin>>n>>m>>l>>r;
    vector<vector<array<int, 2>>> adj(n);
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> dist(n, 1e9);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(pq.size()){
        int u = pq.top()[1];
        int d = pq.top()[0];
        pq.pop();
        if(dist[u] < d)
            continue;
        for(auto c: adj[u]){
            if(dist[c[0]] > d + c[1]){
                dist[c[0]] = d + c[1];
                pq.push({d + c[1], c[0]});
            }
        }
    }
    set<array<int, 2>> ans;
    for(int i = 0; i < n; i++){
        if(2*dist[i] < r){
            for(auto c: adj[i]){
                ans.insert({min(i, c[0]), max(i, c[0])});
            }
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}