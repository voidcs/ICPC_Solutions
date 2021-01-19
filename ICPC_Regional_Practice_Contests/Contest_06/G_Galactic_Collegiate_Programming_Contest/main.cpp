#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, q;
    cin>>n>>q;
    unordered_map<ll, array<ll, 2>> m;
    auto cmp = [](array<ll, 3> a, array<ll, 3> b){
        if(a[0] != b[0]){
            return a[0] > b[0];
        }
        if(a[1] != b[1])
            return a[1] < b[1];
        return a[2] < b[2];
    };
    for(int i = 1; i <= n; i++)
        m[i] = {0, 0};
    set<array<ll, 3>, decltype(cmp)> s(cmp);
    while(q--){
        ll a, b;
        cin>>a>>b;
        if(a != 1)
            s.erase({m[a][0], m[a][1], a});
        m[a][0]++;
        m[a][1] += b;
        function<bool()> better = [&](){
            if(m[a][0] != m[1][0])
                return m[a][0] > m[1][0];
            else if(m[a][1] != m[1][1])
                return m[a][1] < m[1][1];
            return false;
        };
        if(a != 1){
            if(better())
                s.insert({m[a][0], m[a][1], a});
        }
        else{
            s.insert({m[1][0], m[1][1], 1});
            auto it = s.lower_bound({m[1][0], m[1][1], 1});
            while(it != s.end()){
                auto temp = it;
                it++;
                s.erase(temp);
            }
        }
        cout<<s.size() + 1<<endl;
    }
    return 0;
}