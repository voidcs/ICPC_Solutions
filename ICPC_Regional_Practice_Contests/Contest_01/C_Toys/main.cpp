#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    function<int(int, int)> josephus = [&](int n, int k){
        int start = 1;
        for(int i = 1; i <= n; i++){
            start = (start + k - 1) % i + 1;
        }
        return start;
    };
    cout<<josephus(n, k) - 1<<endl;
    return 0;
}