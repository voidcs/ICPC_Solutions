#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    set<ll> s;
    ll hi = -1;
    while(n--){
        ll x;
        cin>>x;
        s.insert(x);
        hi = max(hi, x);
    }
    if(s.size() == hi)
        cout<<"good job\n";
    else{
        for(int i = 1; i <= hi; i++){
            if(!s.count(i))
                cout<<i<<"\n";
        }
    }
    return 0;
}