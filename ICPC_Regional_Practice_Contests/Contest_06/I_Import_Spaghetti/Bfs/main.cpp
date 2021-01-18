#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    map<string, int> mp;
    map<int, string> id;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        id[i] = s;
        mp[s] = i;
    }
    for(int i = 0; i < n; i++){
        string s;
        int m;
        cin>>s>>m;
        for(int j = 0; j < m; j++){
            bool done = 0;
            while(!done){
                cin>>s;
                if(s == "import")
                    continue;
                if(s[s.length()-1] == ','){
                    s.erase(s.length()-1, 1);
                }
                else{
                    done = 1;
                }
                int x = mp[s];
                if(i == x){
                    cout<<s<<endl;
                    return 0;
                }
                adj[i].push_back(x);
            }
        }
    }

    int ans = 1e8;
    vector<int> cycle;
    for(int i = 0; i < n; i++){
        int start;
        vector<int> last(n, -1);
        vector<bool> vis(n, 0);
        queue<array<int,2>> q;
        q.push({i, -1});
        while(!q.empty()){
            int u = q.front()[0];
            int par = q.front()[1];
            q.pop();
            last[u] = par;
            vis[u] = 1;
            int found = -1;
            for(int c: adj[u]){
                if(c == i){
                    found = c;
                    break;
                }
                if(!vis[c]){
                    vis[c] = 1;
                    q.push({c, u});
                }
            }
            if(found != -1){
                vector<int> v;
                int curr = u;
                v.push_back(u);
                while(curr != found){
                    v.push_back(last[curr]);
                    curr = last[curr]; 
                }
                reverse(v.begin(), v.end());
                if((int)v.size() < ans){
                    ans = (int)v.size();
                    cycle = v;
                }
                break;
            }
        }
    }
    if(ans == 1e8)
        cout<<"SHIP IT\n";
    else{
        for(auto x: cycle)
            cout<<id[x]<<" ";
        cout<<endl;
    }
    return 0;
}