#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    ll dist = 1;
    while(n > k){
        ll x = n;
        ll y = 0;
        while(x >= k){
            y += (k-1);
            x -= k;
        }
        if(x)
            y += (x-1);
        n = y;
        dist++;
    }
    dist += n;
    cout<<dist<<endl;
    return 0;
}
