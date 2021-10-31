#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int maxN = 1e6+5;
    vector<ll> fact(maxN);
    fact[0] = fact[1] = 1;
    for(int i = 2; i < maxN; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    auto expo_power = [&](ll base, ll power){
        ll res = 1;
        while(power){
            if(power%2){
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            power /= 2;
        }
        return res;
    };
    
    auto binomial_coefficient = [&](ll x, ll y){
        ll ans = fact[x] * expo_power((fact[y] * fact[x-y]) % mod, mod-2);
        return ans % mod;
    };
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<binomial_coefficient(2*n-1, n)<<endl;
    }
    return 0;
}
