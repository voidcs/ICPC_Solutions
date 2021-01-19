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
    for(int i = 1; i <= n; i++)
        m[i] = {0, 0};
    set<array<ll, 3>, greater<array<ll, 3>>> s;
    while(q--){
        ll a, b;
        cin>>a>>b;
        //If the scoring team isn't team 1, remove so we can update
        if(a != 1)
            s.erase({m[a][0], m[a][1], -a});
        m[a][0]++;
        //Subtract to get negative penalty, this way we don't need comp function
        m[a][1] -= b;
        if(a != 1){
            //Insert -a so that teams of equal score to team 1 come afterwards
            //in the set, thus removing them 
            if(m[a] > m[1])
                s.insert({m[a][0], m[a][1], -a});
        }
        else{
            //Remove all teams with worse scores than team 1 after they score
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