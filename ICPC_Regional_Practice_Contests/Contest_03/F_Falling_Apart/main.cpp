#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a + n);
    reverse(a, a + n);
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0)
            sum1 += a[i];
        else
            sum2 += a[i];
    }
    cout<<sum1<<" "<<sum2<<endl;
    return 0;
}