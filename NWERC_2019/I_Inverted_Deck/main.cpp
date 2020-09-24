#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    vector<int> ans = v;
    sort(ans.begin(), ans.end());
    if(v == ans){
        printf("1 1\n");
        return 0;
    }
    
    int l, r;
    for(int i = 0; i < n; i++){
        if(v[i] != ans[i]){
            l = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(v[i] != ans[i]){
            r = i;
            break;
        }
    }

    reverse(v.begin() + l, v.begin() + r + 1);
    if(v == ans){
        printf("%d %d", l+1, r+1);
    }
    else
        printf("impossible\n");
    return 0;
}



