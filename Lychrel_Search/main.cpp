#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalin(vector<ll>);

int main(){
    
    ll base, x;
    while(cin>>base>>x){
        vector<ll> v;
        while(x){
            v.push_back(x%base);
            x /= base;
        }

        for(auto x: v)
            cout<<x<<" ";
        cout<<endl;
        
        ll ans = 0;
        while(!isPalin(v)){
            vector<ll> r = v;
            reverse(v.begin(), v.end());
            
//            cout<<"Vector: ";
//            for(auto x: v)
//                cout<<x<<" ";
//            cout<<endl;
//            
//            cout<<"Reverse: ";
//            for(auto x: r)
//                cout<<x<<" ";
//            cout<<endl;
            
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
//            cout<<"ADDED VEC: ";
//            for(auto x: n)
//                cout<<x<<" ";
//            cout<<endl;
            ans++;
            
            //cout<<"ANS: "<<ans<<endl;
            if(ans > 500)
                break;
        }
        
        cout<<"ANS: ";
        for(auto x: v)
            cout<<x<<" ";
        cout<<endl;
        
        if(ans <= 500)
            cout<<ans<<" "<<v.size()<<endl;
        else
            cout<<">500\n";
    }
     //999 999 999 999 999 999
    return 0;
}

bool isPalin(vector<ll> v){
    vector<ll> n = v;
    reverse(n.begin(), n.end());
    if(n == v)
        return 1;
    else
        return 0;
}