#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll t;
    cin>>t;
    set<ll> served;
    queue<ll> q;
    priority_queue<array<ll, 2>> pq;
    ll i = 1;
    while(t--){
        ll x, m;
        cin>>x;
        if(x == 1){
            cin>>m;
            q.push(i);
            pq.push({m, -i});
            i++;
        }
        else if(x == 2){
            while(served.count(q.front())){
                q.pop();
            }
            served.insert(q.front());
            cout<<q.front()<<" ";
            q.pop();
        }
        else if(x == 3){
            while(served.count(-1 * pq.top()[1])){
                pq.pop();
            }
            served.insert(-1 * pq.top()[1]);
            cout<<-1 * pq.top()[1]<<" ";
            pq.pop();
        }
        
    }
    return 0;
}