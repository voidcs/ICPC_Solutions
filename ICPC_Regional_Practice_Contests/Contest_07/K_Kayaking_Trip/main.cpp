#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    vector<ll> str(3), freq(3);
    ll n = 0;
    for(int i = 0; i < 3; i++){
        cin>>freq[i];
        n += freq[i];
    }
    for(int i = 0; i < 3; i++)
        cin>>str[i];
    n /= 2;
    vector<ll> speeds(n);
    for(int i = 0; i < n; i++)
        cin>>speeds[i];
    vector<array<ll, 2>> types;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <= i; j++)
            types.push_back({i, j});
    }
    function<bool(array<ll, 2>, array<ll, 2>)> comp = [&](array<ll, 2> a, array<ll, 2> b){
        return str[a[0]] + str[a[1]] < str[b[0]] + str[b[1]];
    };
    sort(speeds.begin(), speeds.end());
    sort(str.begin(), str.end());
    sort(types.begin(), types.end(), comp);

    function<bool(ll)> valid = [&](ll goal){
        vector<ll> temp = freq;
        ll i = n-1;
        for(auto x: types){
            ll sum = str[x[0]] + str[x[1]];
            while(freq[x[0]] >= 1 + (x[0] == x[1]) && freq[x[1]] >= 1 && sum*speeds[i] >= goal){
                i--;
                freq[x[0]]--;
                freq[x[1]]--;
            }
        }
        freq = temp;
        return i < 0;
    };
    ll ans = 0;
    ll l = 0, r = 1e18;
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }
    cout<<ans<<endl;
    
    return 0;
}