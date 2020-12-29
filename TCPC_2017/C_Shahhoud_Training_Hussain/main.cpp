#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll k, p, n;
        cin>>k>>p>>n;
        ll total = n * k;
        p = min(p, k);
        ll solved = p * n;
        cout<<total-solved<<endl;
    }
    return 0;
}