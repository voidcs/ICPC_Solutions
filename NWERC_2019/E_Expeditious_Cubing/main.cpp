#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    long double a[4];
    long double curr = 0;
    for(int i = 0; i < 4; i++){
        cin>>a[i];
    }
    sort(a, a + 4);
    for(int i = 1; i < 4; i++)
        curr += a[i];
    curr /= 3;
    long double win;
    cin>>win;
    
    if(curr <= win){
        cout<<"infinite\n";
        return 0;
    }
    curr = 0;
    for(int i = 0; i < 3; i++){
        curr += a[i];
    }
    curr /= 3;
    if(curr > win){
        cout<<"impossible\n";
        return 0;
    }
    
    cout<<fixed<<setprecision(2)<<(3*win) - a[1] - a[2]<<endl;
    
    return 0;
}


 