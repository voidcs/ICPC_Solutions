#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main() {
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a + n);
    reverse(a, a + n);
    ll flag = 0;
    for(int i = 0; i < n-2; i++){
        if(a[i+1]+a[i+2] > a[i]){
            flag = 1;
        }
    }
    if(flag)
        cout<<"possible\n";
    else
        cout<<"impossible\n";
    return 0;
}