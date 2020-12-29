#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<int> v;
        while(n--){
            vector<int> t(3);
            for(int i = 0; i < 3; i++)
                cin>>t[i];
            sort(t.begin(), t.end());
            for(int i = 0; i < 2; i++)
                v.push_back(t[i]);
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i = 0; i < k; i++)
            ans += v[i];
        cout<<ans<<endl;
    }
    return 0;
}