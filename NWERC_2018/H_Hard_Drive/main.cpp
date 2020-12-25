#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n, c, b;
    cin>>n>>c>>b;
    int a[b];
    set<int> s;
    for(int i = 0; i < b; i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    
    string ans;
    for(int i = 1; i < n; i++){
        if(c == 0)
            break;
        if(i == 1){
            if(s.count(i))
                ans += '0';
            else{
                if(c%2 == 0){
                    ans += '0';
                }
                else{
                    ans += '1';
                    c--;
                }
            }
            continue;
        }
        if(!s.count(i)){
            if(ans[ans.length()-1] == '1'){
                ans += '0';
                continue;
            }
            else{
                ans += '1';
                c -= 2;
            }
        }
        else
            ans += '0';
    }
    while(ans.length() != n-1)
        ans += '0';
    ans += '0';
    cout<<ans<<endl;
    
    return 0;
}