#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin>>n>>k;
    ll a[n];
    ll s = -1;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        s = max(s, a[i]);
    }
    s *= k;
    cout<<(s+999)/1000<<endl;
    return 0;
}