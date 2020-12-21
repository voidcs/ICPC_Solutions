#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, m, k;
    cin>>n>>m>>k;
    ll a[n], b[m], c[k];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i] *= a[i];
    }
    for(int i = 0; i < m; i++)
        cin>>b[i];
    for(int i = 0; i < k; i++)
        cin>>c[i];
    sort(a, a + n);
    
    vector<ll> have;
    for(int i = 0; i < m; i++)
        have.push_back(b[i] * b[i]);
    
    for(int i = 0; i < k; i++){
        ll x = (c[i]/2) * (c[i]/2);
        x *= 2;
        have.push_back(x);
    }
    sort(have.begin(), have.end());
    ll ans = 0, index = have.size()-1;
    for(int i = n-1; i >= 0; i--){
        while(index >= 0 && have[index] >= a[i]){
            index--;
        }
        if(index < 0)
            break;
        if(have[index] < a[i]){
            ans++;
            index--;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
