#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    priority_queue<ll, vector<ll>, greater<ll>> expire;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin>>a>>b;
        pq.push({a, 0});
        pq.push({b, 1});
    }
    ll ans = 0, cnt = 0;
    while(!pq.empty()){
        ll time = pq.top()[0];
        ll exit = pq.top()[1];
        pq.pop();
        if(exit){
            expire.push(time);
        }
        else{
            cnt++;
            while(!expire.empty() && expire.top()+k < time){
                cnt--;
                expire.pop();
            }
            ans = max(ans, cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}
