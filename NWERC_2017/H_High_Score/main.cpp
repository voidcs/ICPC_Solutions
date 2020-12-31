#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 1e18;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a[3];
        ll d;
        for(int i = 0; i < 3; i++)
            cin>>a[i];
        cin>>d;
        sort(a, a + 3);
        reverse(a, a + 3);
        ll ans = 0;
        for(int i = 0; i < 3; i++){
            ll temp[3];
            ll x = 0;
            for(int j = 0; j < 3; j++)
                temp[j] = a[j];
            temp[i] += d;
            for(int j = 0; j < 3; j++)
                x += temp[j] * temp[j];
            sort(temp, temp + 3);
            x += 7 * temp[0];
            ans = max(ans, x);
        }
        
        for(int i = 0; i <= min(d, (ll)100000); i++){
            for(int k = 0; k < 3; k++){
                ll t[3];
                for(int j = 0; j < 3; j++)
                    t[j] = a[j];
                ll forBiggest = d - i;
                ll spread = i;
                ll x = (t[k]+forBiggest);
                t[k] += forBiggest;
                x *= x;
                int b, c;
                if(!k)
                    b = 1, c = 2;
                else if(k == 1)
                    b = 0, c = 2;
                else
                    b = 0, c = 1;
                if(t[b] < t[c])
                    swap(t[b], t[c]);
                if(t[b] - t[c] >= spread){
                    t[c] += spread;
                    x += (t[c]) * (t[c]);
                    x += t[b] * t[b];
                    sort(t, t + 3);
                    x += 7 * t[0];
                }
                else{
                    spread -= t[b] - t[c];
                    t[c] = t[b];
                    t[b] += (spread/2);
                    t[c] += (spread/2);
                    if(spread%2)
                        t[b]++;
                    x += t[b] * t[b];
                    x += t[c] * t[c];
                    sort(t, t + 3);
                    x += 7 * t[0]; 
                }
                ans = max(ans, x);
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}