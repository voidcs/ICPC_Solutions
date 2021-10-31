#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        unordered_set<int> ans;
        for(int i = 2; i*i <= a; i++){
            if(a%i == 0){
                ans.insert(i);
                while(a%i == 0)
                    a /= i;
            }
        }
        for(int i = 2; i*i <= b; i++){
            if(b%i == 0){
                ans.insert(i);
                while(b%i == 0)
                    b /= i;
            }
        }
        if(a != 1)
            ans.insert(a);
        if(b != 1)
            ans.insert(b);
        cout<<ans.size()<<endl;
    }
    return 0;
}
