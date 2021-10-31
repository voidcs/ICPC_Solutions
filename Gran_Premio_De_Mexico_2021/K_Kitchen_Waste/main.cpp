#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> bowl(n), soup(m);
    for(int &x: bowl)
        cin>>x;
    for(int &x: soup)
        cin>>x;
    int j = 0, ans = 0;
    for(int i = 0; i < n; i++){
        while(j < m && soup[j] < bowl[i]){
            j++;
        }
        if(j < m){
            soup[j] -= bowl[i];
        }
    }
    for(int i = 0; i < m; i++){
        ans += soup[i];
    }
    cout<<ans<<endl;
    return 0;
}
