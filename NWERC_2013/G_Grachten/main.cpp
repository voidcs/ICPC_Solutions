#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a, b, c;
    while(cin>>a>>b>>c){
        int n = a * b;
        int d = c-b;
        int g = __gcd(n, d);
        n /= g;
        d /= g;
        cout<<n<<"/"<<d<<endl;
    }
    return 0;
}

