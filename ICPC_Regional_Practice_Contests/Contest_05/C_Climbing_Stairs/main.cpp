#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://open.kattis.com/problems/climbingstairs

int main(){
    ll n, r, k;
    cin>>n>>r>>k;
    ll ans;
    //If the office is above the reception desk
    if(k > r){
        //Max of distance to go up to office then back to reception and the steps needed
        ll walk = 2*k - r;
        walk = max(walk, n);
        //Add distance from reception to ground
        ans = walk + r;
        //If we didn't get enough steps yet and wrong parity, add one
        if(r%2 != n%2 && n > abs(k-r))
            ans++;
    }
    else{
        //We pass our office on the way to reception desk so we only need max(n, r)
        ll walk = max(n, r);
        //Add distance to go back
        ans = walk + r;
        //If we didn't get enough steps yet and wrong parity, add one
        if(r%2 != n%2 && n > abs(k-r))
            ans++;
    }
    cout<<ans<<endl;

    return 0; 
}