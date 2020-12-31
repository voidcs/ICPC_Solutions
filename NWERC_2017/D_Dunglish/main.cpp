#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    map<string, int> total;
    map<string, int> incorrect;
    map<string, int> correct;
    map<string, string> any;
    int d;
    cin>>d;
    vector<array<string, 3>> v;
    while(d--){
        string x, y, z;
        cin>>x>>y>>z;
        v.push_back({x, y, z});
        any[x] = y;
    }
    for(int i = 0; i < v.size(); i++){
        total[v[i][0]]++;
        if(v[i][2] == "correct")
            correct[v[i][0]]++;
        else
            incorrect[v[i][0]]++;
    }
    bool single = 1;
    for(int i = 0; i < n; i++){
        if(total[a[i]] > 1)
            single = 0;
    }
    if(single){
        bool x = 0;
        for(int i = 0; i < n; i++){
            cout<<any[a[i]]<<" ";
            if(incorrect.count(a[i]))
                x = 1;
        }
        cout<<endl;
        if(x)
            cout<<"incorrect\n";
        else
            cout<<"correct\n";
        return 0;
    }
    ll ans1 = 1, ans2 = 1;
    map<string, int> cnt;
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;
		for(auto x: cnt){
			ans1 *= pow(correct[x.first], x.second);
    }

    map<string, int> cnt1;
    for(int i = 0; i < n; i++)
        cnt1[a[i]]++;
		for(auto x: cnt1){
			ans2 *= pow(total[x.first], x.second);
    }
    ans2 -= ans1;
    
    cout<<ans1<<" "<<"correct\n";
    cout<<ans2<<" "<<"incorrect\n";
    
    return 0;
}