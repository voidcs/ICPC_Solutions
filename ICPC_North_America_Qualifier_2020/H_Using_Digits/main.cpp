#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>m>>n;
    string s;
    cin>>s;
    vector<vector<int>> g(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin>>c;
            g[i][j] = c - '0';
        }
    }
    int dp[n][m][s.length()+1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k <= s.length(); k++)
                dp[i][j][k] = 1e8;
        
    dp[n-1][0][0] = g[n-1][0];
    
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            for(int k = 0; k <= s.length(); k++){
                if(i-1 >= 0)
                    dp[i-1][j][k] = min(dp[i-1][j][k], dp[i][j][k] + g[i-1][j]);
                if(j+1 < m)
                    dp[i][j+1][k] = min(dp[i][j+1][k], dp[i][j][k] + g[i][j+1]);
                if(k == s.length())
                    continue;
                int d = s[k] - '0';
                if(i-d-1 >= 0)
                    dp[i-d-1][j][k+1] = min(dp[i-d-1][j][k+1], dp[i][j][k] + g[i-d-1][j]);
                if(j+d+1 < m)
                    dp[i][j+d+1][k+1] = min(dp[i][j+d+1][k+1], dp[i][j][k] + g[i][j+d+1]);
            }
        }
    }
    
    int ans = 1e8;
    for(int i = 0; i <= s.length(); i++)
        ans = min(ans, dp[0][m-1][i]);
    cout<<ans<<endl;
    return 0;
}