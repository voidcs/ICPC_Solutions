#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        ans = min(ans, y/x);
    }
    cout<<ans<<endl;
    return 0;
}