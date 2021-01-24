#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    map<long double, string> m;
    cin>>n;
    vector<array<long double, 2>> first(n), after(n);
    for(int i = 0; i < n; i++){
        long double x, y;
        string s;
        cin>>s>>x>>y;
        first[i] = {x, (long double)i};
        after[i] = {y, (long double)i};
        m[i] = s;
    }
    sort(first.begin(), first.end());
    sort(after.begin(), after.end());
    long double ans = INF;
    vector<string> ans2(4);
    
    for(int i = 0; i < n; i++){
        vector<string> used;
        long double sum = first[i][0];
        used.push_back(m[first[i][1]]);
        set<long double> s;
        for(int j = 0; j < 4; j++){
            if(used.size() == 4)
                break;
            if(after[j][1] != first[i][1]){
                used.push_back(m[after[j][1]]);
                sum += after[j][0];
            }
        }
        if(sum < ans){
            ans = sum;
            ans2 = used;
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    for(auto x: ans2)
        cout<<x<<endl;
    return 0;
}