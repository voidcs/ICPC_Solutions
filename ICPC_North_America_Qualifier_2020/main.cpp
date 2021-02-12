#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    map<string, int> wordToId;
    map<int, string> idToWord;
    vector<set<int>> adj(n+1);
    vector<string> understand(n+1);
    int count = 0;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int len = s.length();
        vector<string> words;
        for(int j = 0; j < len; j++){
            string t;
            while(j < len && !isspace(s[j])){
                t += s[j];
                j++;
            }
            words.push_back(t);
            if(!wordToId.count(t) && words.size() > 1){
                wordToId[t] = count;
                idToWord[count] = t;
                count++;
            }
        }
        understand[i] = words[1];
        for(int j = 1; j < words.size(); j++){
            adj[i].insert(wordToId[words[j]]);
        }
    }
    vector<vector<int>> adj2(n+1), adj3(n+1);
    for(int i = 0; i < n; i++){
        int speak = wordToId[understand[i]];
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            if(adj[j].count(speak)){
                adj2[i].push_back(j);
                adj3[j].push_back(i);
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i < n; i++){
        vector<int> vis(n+1, 0);
        vector<int> vis2(n+1, 0);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(int c: adj2[u]){
                if(!vis[c]){
                    vis[c] = 1;
                    dfs(c);
                }
            }
        };
        function<void(int)> dfs2 = [&](int u){
            vis2[u] = 1;
            for(int c: adj3[u]){
                if(!vis2[c]){
                    vis2[c] = 1;
                    dfs2(c);
                }
            }
        };
        dfs(i);
        dfs2(i);
        int canTalk = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] && vis2[i])
                canTalk++;
        }
        ans = min(ans, n - canTalk);
    }
    cout<<ans<<endl;
    

    return 0;
}