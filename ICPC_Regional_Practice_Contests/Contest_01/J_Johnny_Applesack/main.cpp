#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    ll r = n;
    ll ans = 1;
    while(r > k){
        ans++;
        ll x = 0;
        x += r / k;
        ll y = x * (k-1);
        r -= (x * k);
        //cout<<"r: "<<r<<"   ";
        if(r)
            y += (r-1);
        r = y;
        //cout<<"x: "<<x<<"  y: "<<y<<endl;
    }
    ans += r;
    cout<<ans<<endl;
    return 0;
}