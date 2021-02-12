#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n;
    cin>>n;
    vector<array<ll, 2>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0];
        v[i][1] = i+1;
    }
    ll i = 0;
    while(v.size() > 1){
        ll steps= v[i][0]-1;
        ll remove = (i+steps)%v.size();
        i = (remove+1)%v.size();
        if(i > remove)
            i--;
        v.erase(v.begin()+remove);
    }
    cout<<v[0][1]<<endl;
    
    
    return 0;
} 