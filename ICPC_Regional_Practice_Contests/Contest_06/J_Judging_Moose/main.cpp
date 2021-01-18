#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll l, r;
    cin>>l>>r;
    if(l == 0 && r == 0)
        cout<<"Not a moose\n";
    else if(l == r){
        cout<<"Even ";
        cout<<l+r<<endl;
    }
    else{
        cout<<"Odd ";
        cout<<max(l, r)*2<<endl;
    }
    return 0; 
}