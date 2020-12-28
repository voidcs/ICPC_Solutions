#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> t(n), deg(n);

    for(int i = 0; i < n; i++){
        cin>>t[i];
        int z;
        cin>>z;
        while(z--){
            int u;
            cin>>u;
            u--;
            deg[u]++;
            adj[i].push_back(u);
        }
    }
    
//    cout<<"in: ";
//    for(int i = 0; i < n; i++)
//        cout<<right<<setw(2)<<deg[i]<<" ";
//    cout<<endl;
//    
//    for(int i = 0; i < n; i++){
//        cout<<i<<": ";
//        for(int c: adj[i])
//            cout<<c<<" ";
//        cout<<endl;
//    }
    
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for (int v = 0; v < n; v++){
        if (deg[v] == 0)
            pq.push({t[v], v});
    }
    
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int u = pq.top()[1];
        //cout<<"u: "<<u<<"   t[u]: "<<t[u]<<"   i: "<<i<<endl;
        pq.pop();
        ans = max(ans, t[u] + i);
        for (int c: adj[u]) {
            deg[c]--;
            if (deg[c] == 0) 
                pq.push({t[c], c});
        }
    }
    cout<<ans<<endl;
	
    return 0;
}
