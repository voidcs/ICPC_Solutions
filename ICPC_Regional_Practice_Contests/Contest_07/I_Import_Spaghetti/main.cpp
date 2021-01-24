#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    map<string, ll> id;
    map<ll, string> idToName;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        id[s] = i;
        idToName[i] = s;
    }
    vector<vector<ll>> adj(n);
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        ll q;
        cin>>q;
        while(q--){
            cin>>s;
            bool flag = 1;
            while(flag){
                cin>>s;
                if(s.back() == ','){
                    string t;
                    for(int k = 0; k < s.length()-1; k++)
                        t += s[k];
                    s = t;
                }
                else
                    flag = 0;
                adj[i].push_back(id[s]);
            }
        }
    }
    ll ans = INF;
    vector<ll> cycle;
    for(int i = 0; i < n; i++){
        vector<ll> last(n, -1), vis(n, 0);
        queue<ll> q;
        q.push(i);
        ll found = -1;
        while(!q.empty()){
            ll u = q.front();
            vis[u] = 1;
            q.pop();
            for(int c: adj[u]){
                if(c == i){
                    found = u;
                    last[c] = u;
                    break;
                }
                if(!vis[c]){
                    last[c] = u;
                    vis[c] = 1;
                    q.push(c);
                }
            }
            if(found != -1){
                ll curr = u;
                vector<ll> path;
                path.push_back(u);
                while(last[curr] != found){
                    path.push_back(last[curr]);
                    curr = last[curr];
                }
                reverse(path.begin(), path.end());
                if((ll)path.size() < ans){
                    ans = (ll)path.size();
                    cycle = path;
                }
                break;
            }
        }
    }
    if(ans == INF)
        cout<<"SHIP IT\n";
    else{
        for(auto x: cycle)
            cout<<idToName[x]<<" ";
    }
    return 0;
}