#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

struct answer{
    string names[4];
    long double time;
};

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    map<ll, string> m;
    array<long double, 2> goSecond [n];
    array<long double, 2> check [n];
    for(int i = 0; i < n; i++){
        string name;
        cin>>name;
        m[i] = name;
        long double a, b;
        cin>>a>>b;
        check[i] = {a, (long double)i};
        goSecond[i] = {b, (long double)i};
    }
    sort(check, check + n);
    sort(goSecond, goSecond + n);
    
    answer ans;
    ans.time = 1e18;
    for(int i = 0; i < n; i++){
        set<ll> id;
        ll cnt = 0, index = 0;
        long double total = 0;
        for(int j = 0; j < 4; j++){
            if(cnt == 3)
                break;
            if(goSecond[j][1] != check[i][1]){
                id.insert(goSecond[j][1]);
                total += goSecond[j][0];
                cnt++;
            }
        }
        total += check[i][0];
        if(total < ans.time){
            ans.time = total;
            ans.names[0] = m[check[i][1]];
            int j = 1;
            for(auto x: id){
                ans.names[j] = m[x];
                j++;
            }
        }
    }
    cout<<fixed<<setprecision(10)<<ans.time<<endl;
    for(int i = 0; i < 4; i++)
        cout<<ans.names[i]<<endl;
    return 0; 
}