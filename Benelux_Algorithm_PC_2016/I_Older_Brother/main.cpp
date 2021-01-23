#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main() {
    ll n;
    cin>>n;
    map<ll, ll> factors;
    if(n == 1){
        cout<<"no\n";
        return 0;
    }
    for(int i = 2; i*i <= n; i++){
        ll cnt = 0;
        while(n%i == 0){
            n /= i;
            cnt++;
        }
        if(cnt)
            factors[i] = cnt;
    }
    if(n != 1)
        factors[n] = 1;
    
//    for(auto x: factors){
//        cout<<x.first<<"  "<<x.second<<endl;
//    }
    if(factors.size() > 1)
        cout<<"no\n";
    else{
        cout<<"yes\n";
    }
    
    return 0;
}