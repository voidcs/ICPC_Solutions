#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll l, r;
    cin>>l>>r;
    if(l == 0 && r == 0)
        cout<<"Not a moose\n";
    else if(l == r)
        cout<<"Even "<<l+r<<endl;
    else
        cout<<"Odd "<<max(l, r)*2<<endl;
    
    return 0;
}