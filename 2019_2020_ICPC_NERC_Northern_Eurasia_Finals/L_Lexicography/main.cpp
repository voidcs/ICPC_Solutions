#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, l, k;
    cin>>n>>l>>k;
    string alpha;
    cin>>alpha;
    map<char, int> m;
    for(int i = 0; i < alpha.size(); i++){
        m[alpha[i]]++;
    }
    vector<string> ans(n);
    for(int i = 0; i < k; i++){
        char c = m.begin()->first;
        ans[i] += c;
        m[c]--;
        if(m[c] == 0)
            m.erase(c);
    }
    //Find the first string with the same first letter as the kth
    int start = -1;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == ans[k-1]){
            start = i;
            break;
        }
    }
    bool flag = 0;
    //Use our best letters to create the kth string first
    while(ans[k-1].length() != l){
        for(int i = start; i < k; i++){
            if(flag && i != k-1)
                continue;
            char c = m.begin()->first;
            ans[i] += c;
            m[c]--;
            if(m[c] == 0)
                m.erase(c);
        }
        //Check if the last letters match, if they do then we must keep the
        //strings before k lexicographically smaller
        //If the last letters do not match, then this string will be bigger
        //than string k anyways so we can save better letters
        for(int i = start; i < k; i++){
            if(ans[i].back() == ans[k-1].back()){
                start = i;
                break;
            }
        }
    }
    
    //Fill the remaining words with the rest of the letters we have
    for(int i = 0; i < n; i++){
        while(ans[i].length() != l){
            char c = m.begin()->first;
            ans[i] += c;
            m[c]--;
            if(m[c] == 0)
                m.erase(c);
        }
    }
    for(auto x: ans)
        cout<<x<<endl;

    return 0;
}