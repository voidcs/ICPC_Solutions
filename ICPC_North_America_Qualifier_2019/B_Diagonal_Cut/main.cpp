#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, m;
    cin>>n>>m;
    ll g = __gcd(n, m);
    n /= g, m /= g;
    if(n%2 && m%2)
        cout<<g<<endl;
    else
        cout<<"0\n";
    
    return 0;
}