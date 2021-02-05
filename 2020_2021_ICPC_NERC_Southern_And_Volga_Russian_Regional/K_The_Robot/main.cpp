#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        ll n = str.length();
        ll x = 0, y = 0;
        set<array<ll, 2>> s;
        array<ll, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i < 4; i++)
            s.insert({x+dir[i][0], y + dir[i][1]});
            
        for(char c: str){
            if(c == 'U')
                y++;
            else if(c == 'D')
                y--;
            else if(c == 'L')
                x--;
            else if(c == 'R')
                x++;
            for(int i = 0; i < 4; i++){
                s.insert({x+dir[i][0], y + dir[i][1]});
            }
        }
        s.erase({0, 0});
        array<ll, 2> ans;
        bool found = 0;
        for(auto blocked: s){
            x = 0, y = 0;
            for(char c: str){
                if(c == 'U' && (x != blocked[0] || y+1 != blocked[1]))
                    y++;
                else if(c == 'D' && (x != blocked[0] || y-1 != blocked[1]))
                    y--;
                else if(c == 'L' && (x-1 != blocked[0] || y != blocked[1]))
                    x--;
                else if(c == 'R' && (x+1 != blocked[0] || y != blocked[1]))
                    x++;
            }
            //cout<<"blocked: "<<blocked[0]<<" "<<blocked[1]<<"   x: "<<x<<"   y: "<<y<<endl;
            if(x == 0 && y == 0){
                found = 1;
                ans[0] = blocked[0], ans[1] = blocked[1];
                break;
            }  
        }
        if(found){
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
        else
            cout<<"0 0\n";
    }
    return 0;
}