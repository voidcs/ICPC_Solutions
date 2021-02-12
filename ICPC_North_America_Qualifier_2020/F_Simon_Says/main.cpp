#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        int n = s.length();
        vector<string> v;
        for(int i = 0; i < n; i++){
            string t;
            while(i < n && !isspace(s[i])){
                t += s[i];
                i++;
            }
            v.push_back(t);
        }

        if(v.size() >= 2 && v[0] == "Simon" && v[1] == "says"){
            for(int i = 2; i < v.size(); i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
    }

    return 0;
}