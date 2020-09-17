#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6091

int main(){
    string str;
    while(cin>>str){
        string str1, str2;
        int n = str.length();
        for(int i = 0; i < n/2; i++)
            str1 += str[i];
        for(int i = n/2; i < n; i++)
            str2 += str[i];
        
        int val = 0;
        for(int i = 0; i < str1.length(); i++){
            val += str1[i] - 'A';
        }
        val %= 26;
        for(int i = 0; i < str1.length(); i++){
            str1[i] += val;
            if(str1[i] > 'Z')
                str1[i] -= 26;
        }
        val = 0;
        for(int i = 0; i < str2.length(); i++){
            val += str2[i] - 'A';
        }
        val %= 26;
        for(int i = 0; i < str2.length(); i++){
            str2[i] += val;
            if(str2[i] > 'Z')
                str2[i] -= 26;
        }
        
        for(int i = 0; i < str1.length(); i++){
            str1[i] += str2[i] - 'A';
            if(str1[i] > 'Z')
                str1[i] -= 26;
        }
        cout<<str1<<endl;
    }
    return 0;
}



