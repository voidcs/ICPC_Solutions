#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    string a, b;
    cin>>a>>b;
    string ans;
    ll cnt = 1;
    string de = a;
    while(ans.length() + n < m){
        string t;
        for(int i = 0; i < n; i++){
        int x = (b[m-(n*cnt)+i] - 'a') - (de[i] - 'a');
            x = (x+26) % 26;
            char c = 'a' + x;
            t += c;
        }
        cnt++;
        ans = (t + ans);
        de = t;
    }
    string ans2;
    for(int i = 0; i < m-n; i++){
        ans2 += ans[ans.length()-1-i];
    }
    reverse(ans2.begin(), ans2.end());
    cout<<ans2<<a<<endl;
    return 0;
}