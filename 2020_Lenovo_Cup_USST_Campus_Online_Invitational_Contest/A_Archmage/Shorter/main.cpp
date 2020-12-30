#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t = 0; 
    cin>>t; 
    while(t--) {
		ll n, m, x, y;
        cin>>n>>m>>x>>y;

        ll mana = n + (m - 1) * y;
        ll ans = mana / x;

        cout<<min(ans, m)<<endl;
    }
    return 0;
}