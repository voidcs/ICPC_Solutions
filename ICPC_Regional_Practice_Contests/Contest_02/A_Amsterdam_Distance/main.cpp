#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    //freopen("input1.txt", "r", stdin);
    ll n, m;
    long double r;
    ll x1, r1, x2, r2;
    cin>>n>>m>>r;
    cin>>r1>>x1>>r2>>x2;
    long double ans = 0;
    long double d = abs(x1 - x2);
    d = (d/m) * r;
    ans += d;
    d = abs(r1 - r2);
    long double z = min(x1, x2);
    long double ang = 180 * (d/n);
    ans += (M_PI*2) * (r*(z/m)) * (ang/360);
    long double ans2 = ((long double)x1 / m) * r;
    ans2 += ((long double)x2 / m) * r;
    ans = min(ans, ans2);
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}