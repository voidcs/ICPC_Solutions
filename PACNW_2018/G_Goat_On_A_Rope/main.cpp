#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    long double x, y, x1, x2, y1, y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    vector<pair<int, int>> corners;
    corners.push_back({x1, y1});
    corners.push_back({x2, y2});
    corners.push_back({x2, y1});
    corners.push_back({x1, y2});
    
    long double ans = 1e10;
    for(int i = 0; i < 4; i++){
        long double a, b;
        //cout<<"TO ("<<corners[i].first<<", "<<corners[i].second<<")\n";
        a = abs(x - corners[i].first);
        b = abs(y - corners[i].second);
        
//        cout<<"a: "<<a<<endl;
//        cout<<"b: "<<b<<endl;
        long double c = sqrt((a*a) + (b*b));
        //cout<<"C: "<<c<<endl;
        ans = min(ans, c);
    }
    
    if(x >= x1 && x <= x2){
        ans = min(ans, abs(y - y1));
        ans = min(ans, abs(y - y2));
    }
    if(y >= y1 && y <= y2){
        ans = min(ans, abs(x - x1));
        ans = min(ans, abs(x - x2));
    }
    cout<<fixed<<setprecision(3)<<ans<<endl;
    
    return 0;
}