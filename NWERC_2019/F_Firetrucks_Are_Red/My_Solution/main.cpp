#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> par;

int find(int i){
    return (i == par[i]) ? i : (par[i] = find(par[i]));
}

void unite(int x, int y){
    x = find(x), y = find(y);
    if(x != y){
        par[x] = y;
    }
}

struct S{
    int a;
    int b;
    int c;
};

int main(){
    ll n;
    cin>>n;
    par = vector<int> (n+1);
    iota(par.begin(), par.end(), 0);
    map<int, int> m;
    vector<S> ans;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            int r;
            if(m.count(x)){
                r = m[x];
                if(find(i) != find(r)){
                    ans.push_back({i, r, x});
                    unite(i, r);
                }
            }
            else
                m[x] = i;
        }
    }

    if(ans.size() == n-1){
        for(int i = 0; i < n-1; i++){
            cout<<ans[i].a + 1<<" "<<ans[i].b + 1<<" "<<ans[i].c<<endl;
        }
    }
    
    else
        cout<<"impossible\n";
    
    return 0;
}