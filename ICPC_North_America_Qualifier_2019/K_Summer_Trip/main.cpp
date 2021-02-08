#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    string s;
    cin>>s;
    ll n = s.length();
    ll ans = 0;
    for(int i = 0; i < n; i++){
        set<char> have;
        for(int j = i+1; j < n; j++){
            if(s[i] == s[j])
                break;
            else if(!have.count(s[j])){
                ans++;
                have.insert(s[j]);
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
} 