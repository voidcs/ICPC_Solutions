#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    string s;
    cin>>s;
    ll n = s.length();
    ll l = 0, r = n-1;
    ll ans = 0;
    while(l <= r){
        ll cnt = 0;
        if(s[l] != s[r]){
            break;
        }
        char c = s[l];
        while(l < n && l <= r && s[l] == c){
            l++;
            cnt++;
        }
        while(r >= 0 && r >= l && s[r] == c){
            r--;
            cnt++;
        }
        if(l > r){
            if(cnt >= 2)
                ans = cnt+1;
        }
        else{
            if(cnt <= 2)
                break;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}