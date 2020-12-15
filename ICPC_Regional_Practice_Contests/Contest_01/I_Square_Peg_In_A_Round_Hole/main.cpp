#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, m, k;
    cin>>n>>m>>k;
    ll a[n], b[m], c[k];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>b[i];
    for(int i = 0; i < k; i++)
        cin>>c[i];
    sort(a, a + n);
    sort(b, b + m);
    sort(c, c + k);
    for(int i = 0; i < n; i++)
        a[i] *= a[i];
    vector<ll> req;
    for(int i = 0; i < k; i++){
        ll x = (c[i]/2)*(c[i]/2);
        x *= 2;
        req.push_back(x);
    }
    for(int i = 0; i < m; i++)
        req.push_back(b[i] * b[i]);
    sort(req.begin(), req.end());

    ll ans = 0;
    int j = req.size()-1;
    for(int i = n-1; i >= 0; i--){
        while(req[j] >= a[i] && j >= 0){
            j--;
        }
        if(j < 0)
            break;
        if(req[j] < a[i]){
            ans++;
            j--;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}