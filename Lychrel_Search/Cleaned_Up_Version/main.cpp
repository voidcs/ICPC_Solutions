#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalin(vector<ll> v){
    vector<ll> n = v;
    reverse(n.begin(), n.end());
    return (n == v);
}

int main(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ll base, x;
    while(cin>>base>>x){
        vector<ll> v;
        while(x){
            v.push_back(x%base);
            x /= base;
        }
        
        ll ans = 0;
        while(!isPalin(v)){
            vector<ll> r = v;
            reverse(v.begin(), v.end());
            vector<ll> n;
            int carry = 0;
            for(int i = 0; i < v.size(); i++){
                ll add = v[i] + r[i] + carry;
                if(add >= base){
                    carry = 1;
                    add -= base;
                }
                else
                    carry = 0;
                n.push_back(add);
            }
            
            if(carry)
                n.push_back(1);
            reverse(n.begin(), n.end()); 
            v = n;
            ans++;
            if(ans > 500)
                break;
        }
        if(ans <= 500)
            cout<<ans<<" "<<v.size()<<endl;
        else
            cout<<">500\n";
    }
    return 0;
}