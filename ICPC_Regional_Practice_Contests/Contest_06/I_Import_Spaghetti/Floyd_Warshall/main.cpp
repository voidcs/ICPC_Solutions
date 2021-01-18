#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    map<string, ll> mp;
    map<ll, string> id;
    
    function<void(int,int)> printpath = [&](int u, int ans) {
        for(int i = 0; i < n; i++){
            //If distance from curr node to i is 1 AND (dist i to ans is one less than dist curr to ans OR dist curr to ans is 1))
            if(dist[u][i] == 1 && (dist[i][ans] == dist[u][ans]-1 || dist[u][ans] == 1)){
                cout<<id[u]<<" ";
                //if dist current node to ans is greater than one, continue path
                if(dist[u][ans] > 1)
                    printpath(i, ans);
                break;
            }
        }
    };
    
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
                ll x = mp[s];
                if(i == x){
                    cout<<s<<endl;
                    return 0;
                }
                dist[i][x] = 1;
            }
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    ll s = 0;
    for(int i = 0; i < n; i++){
        if(dist[i][i] < dist[s][s])
            s = i;
    }
    
    if(dist[s][s] == INF){
        cout<<"SHIP IT\n";
    }
    else{
        printpath(s, s);
    }
    return 0;
}