#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int sum = 0;
        sum += s[0] - '0';
        sum += s[2] - '0';
        cout << sum << endl;
    }
    
    return 0;
}