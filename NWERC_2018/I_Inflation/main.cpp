#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n;
    cin>>n;
    long double a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    long double ans = 1e18;
    for(int i = 0; i < n; i++){
        long double x = a[i] / ((long double)i+1);
        if(x > 1){
            cout<<"-1\n";
            return 0;
        }
        ans = min(ans, x);
    }

    cout<<fixed<<setprecision(20)<<ans<<endl;
    return 0;
}