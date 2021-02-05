#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    char a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int val[n];
    for(int i = 0; i < n; i++){
        if(a[i] == 'T')
            val[i] = 1;
        else
            val[i] = 0;
    }
    string str;
    cin.ignore();
    getline(cin, str);
    stack<int> s;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ')
            continue;
        if(isalpha(str[i])){
            s.push(val[str[i]-'A']);
        }
        else{
            if(str[i] == '*'){
                ll x = s.top();
                s.pop();
                ll y = s.top();
                s.pop();
                s.push(x&y);
            }
            else if(str[i] == '+'){
                ll x = s.top();
                s.pop();
                ll y = s.top();
                s.pop();
                s.push(x|y);
            }
            else{
                ll x = s.top();
                s.pop();
                s.push(!x);
            }
        }
    }
    if(s.top() == 0)
        cout<<"F\n";
    else
        cout<<"T\n";
    
    return 0;
}