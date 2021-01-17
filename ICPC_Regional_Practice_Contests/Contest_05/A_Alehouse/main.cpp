#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://open.kattis.com/problems/alehouse

int main(){
    ll n, k;
    cin>>n>>k;
    array<ll, 2> a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1];
    sort(a, a + n);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    priority_queue<ll, vector<ll>, greater<ll>> expire;
    for(int i = 0; i < n; i++){
        pq.push({a[i][0], 0});
        pq.push({a[i][1], 1});
    }
    ll ans = 0, last = INF, cnt = 0, left;
    while(!pq.empty()){
        ll exit = pq.top()[1];
        ll time = pq.top()[0];
        pq.pop();
        if(exit){
            expire.push(time);
            ans = max(ans, cnt);
        }
        else{
            while(!expire.empty() && expire.top()+k < time){
                cnt--;
                expire.pop();
            }
            cnt++;
            ans = max(ans, cnt);
            while(!expire.empty() && expire.top()+k == time){
                cnt--;
                expire.pop();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}