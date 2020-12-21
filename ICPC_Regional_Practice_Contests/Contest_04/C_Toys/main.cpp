#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans = (ans+k) % i;
    cout<<ans<<endl;
    return 0;
}