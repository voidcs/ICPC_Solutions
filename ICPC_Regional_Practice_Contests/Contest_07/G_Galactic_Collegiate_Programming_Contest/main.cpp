#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, q;
    cin>>n>>q;
    map<ll, array<ll, 3>> m;
    for(int i = 0; i < n; i++)
        m[i] = {0, 0, -i};
    
    set<array<ll, 3>, greater<array<ll, 3>>> s;
    while(q--){
        ll a, b;
        cin>>a>>b;
        a--;
        if(a != 0)
            s.erase(m[a]);
        m[a][0]++;
        m[a][1] -= b;
        if(a == 0){
            s.insert(m[a]);
            auto it = s.lower_bound(m[a]);
            while(it != s.end()){
                auto t = it;
                it++;
                s.erase(t);
            }
        }
        else{
            if(m[a] > m[0]){
                s.insert(m[a]);
            }
        }
//        for(auto x: s)
//            cout<<x[0]<<" "<<x[1]<<endl;
        cout<<s.size()+1<<endl;
    }
    return 0;
}