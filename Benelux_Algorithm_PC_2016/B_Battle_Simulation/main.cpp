#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main() {
    string str;
    cin>>str;
    ll n = str.length();
    map<char, char> ans;
    ans['R'] = 'S';
    ans['B'] = 'K';
    ans['L'] = 'H';
    for(int i = 0; i < n; i++){
        set<char> s;
        for(int j = i; j < i+3 && j < n; j++){
            s.insert(str[j]);
        }
        if(s.size() == 3){
            cout<<'C';
            i += 2;
        }
        else{
            cout<<ans[str[i]];
        }
    }
    return 0;
}