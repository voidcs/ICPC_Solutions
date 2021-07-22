#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    cin.ignore();
    map<string, int> m, last;
    int freq = 0;
    for(int i = 0; i < 3*n; i++){
        string s;
        getline(cin, s);
        m[s]++;
        last[s] = i;
        freq = max(freq, m[s]);
    }
    vector<string> ans;
    for(auto x: m){
        ans.push_back(x.first);
    }
    auto comp = [&](string a, string b){
        if(m[a] != m[b])
            return m[a] > m[b];
        return last[a] > last[b];
    };
    sort(ans.begin(), ans.end(), comp);
    for(int i = 0; i < min((int)ans.size(), k); i++)
        cout<<ans[i]<<endl;
    return 0;
}