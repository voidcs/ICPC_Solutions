#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    vector<ll> freq(3), str(3);
    ll n = 0;
    for(int i = 0; i < 3; i++){
        cin>>freq[i];
        n += freq[i];
    }
    for(int i = 0; i < 3; i++)
        cin>>str[i];
    n /= 2;
    ll speeds[n];
    for(int i = 0; i < n; i++)
        cin>>speeds[i];
    //Holds the different types of pairings of skill levels
    vector<array<ll, 2>> types;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <= i; j++)
            types.push_back({i, j});
    //Sort them according to lowest to highest strength sum
    function<bool(array<ll, 2>, array<ll, 2>)> comp = [&](array<ll, 2> a, array<ll, 2> b){
        return (str[a[0]]+str[a[1]] < str[b[0]]+str[b[1]]);
    };
    sort(speeds, speeds + n);
    sort(types.begin(), types.end(), comp);
    
    function<bool(vector<ll>, ll)> valid = [&](vector<ll> f, ll minimum){
        //Set i to n-1 to start from the highest speed factors
        ll i = n-1;
        for(auto x: types){
            ll sum = str[x[0]] + str[x[1]];
            //Greedily match the smallest sums with the highest speed factors to
            //see if it's enough for the value we are binary searching
            while(i >= 0 && f[x[0]] >= 1 + (x[0] == x[1]) && f[x[1]] >= 1 && sum*speeds[i] >= minimum){
                i--;
                f[x[0]]--;
                f[x[1]]--;
            }
        }
        return i == -1;
    };
    ll ans = 0;
    ll l = 0, r = 1e10;
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(freq, mid)){
            l = mid+1;
            ans = mid;
        }
        else
            r = mid-1;
    }
    cout<<ans<<endl;
    
    return 0;
}
