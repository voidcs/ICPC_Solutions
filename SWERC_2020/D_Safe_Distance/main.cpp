#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //Binary search over the answer
    //Rethink of the problem as what is the biggest radius of each point that will 
    //Not block us from reaching the end
    //If two circles overlap, we apply dsu and store their min/max X value and min/max Y value
    int n, x, y;
    cin>>x>>y>>n;
    vector<array<long double, 2>> v(n);
    for(auto &x: v)
        cin>>x[0]>>x[1];
    long double ans = 0, eps = 1e-8;
    long double l = 0, r = 1e8;
    auto valid = [&](long double r){
        vector<long double> minX(n, INF), maxX(n, -INF), minY(n, INF), maxY(n, -INF);
        vector<int> par(n, -1);
        function<int(int)> find = [&](int x){
            return (par[x] < 0) ? x : par[x] = find(par[x]);
        };
        auto unite = [&](int x, int y){
            x = find(x), y = find(y);
            if(par[x] > par[y])
                swap(x, y);
            if(x != y){
                par[x] += par[y];
                minX[x] = min(minX[x], minX[y]);
                maxX[x] = max(maxX[x], maxX[y]);
                minY[x] = min(minY[x], minY[y]);
                maxY[x] = max(maxY[x], maxY[y]);
                par[y] = x;
            }
        };
        for(int i = 0; i < n; i++){
            minX[i] = v[i][0] - r;
            maxX[i] = v[i][0] + r;
            minY[i] = v[i][1] - r;
            maxY[i] = v[i][1] + r;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long double dist = ( (v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) ) + ( (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]) );
                if(2*r > sqrt(dist)){
                    unite(i, j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            int u = find(i);
            if(par[u] >= 0)
                continue;
            if(minX[u] < 0 && maxX[u] > x)
                return false;
            if(minY[u] < 0 && maxY[u] > y)
                return false;
            if(minX[u] < 0 && minY[u] < 0)
                return false;
            if(maxX[u] > x && maxY[u] > y)
                return false;
        }
        return true;
    };
    while(l + eps < r){
        long double m = (l+r)/2;
        if(valid(m)){
            ans = m;
            l = m;
        }
        else
            r = m;
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;

    return 0;
}
