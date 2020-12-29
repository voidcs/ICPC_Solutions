#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int total = 0;
        for (int i = 0; i < n-1; i++)
        {
            int x;
            cin >> x;
            total += x;
        }
        cout << ((n*(n+1))/2) - total << endl;
    }
}