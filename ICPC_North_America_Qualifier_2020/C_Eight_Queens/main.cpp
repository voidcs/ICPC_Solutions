#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    vector<vector<char>> g(8, vector<char>(8));
    int n = 8;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>g[i][j];
        }
    }
    bool flag = 1;
    array<int, 2> dir[8] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    
    function<bool(int, int)> valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == '.')
                continue;
            for(int k = 0; k < 8; k++){
                for(int d = 1; d < 8; d++){
                    int nx = i + (dir[k][0]*d);
                    int ny = j + (dir[k][1]*d);
                    if(valid(nx, ny) && g[nx][ny] == '*'){
                        flag = 0;       
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == '*')
                cnt++;
        }
    }
    if(cnt != 8)
        flag = 0;
    if(flag)
        cout<<"valid\n";
    else
        cout<<"invalid\n";
    
    return 0;
}