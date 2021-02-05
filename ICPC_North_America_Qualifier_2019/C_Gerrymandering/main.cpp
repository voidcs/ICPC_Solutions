#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll q, n;
    cin>>q>>n;
    vector<array<ll, 2>> a(n+1);
    while(q--){
        ll d, x, y;
        cin>>d>>x>>y;
        a[d][0] += x;
        a[d][1] += y;
    }
    long double eg = 0;
    ll num = 0, denom = 0;
    ll sumX = 0, sumY = 0;
    for(int i = 1; i <= n; i++){
        ll win = ((a[i][0]+a[i][1])/2)+1;
        ll wasteA, wasteB;
        if(a[i][0] > a[i][1]){
            cout<<"A ";
            wasteA = a[i][0]-win, wasteB = a[i][1];
        }
        else{
            cout<<"B ";
            wasteA = a[i][0], wasteB = a[i][1]-win;
        }
        cout<<wasteA<<" "<<wasteB<<endl;
        sumX += wasteA, sumY += wasteB;
        denom += (a[i][0]+a[i][1]);
    }
    cout<<fixed<<setprecision(20)<<(long double)(abs(sumX-sumY)) / (long double)denom<<endl;
    return 0;
}