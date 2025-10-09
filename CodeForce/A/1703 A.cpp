#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;

        for(auto &c : s)
        {
            c = tolower(c);
        }
        cout << ( s == "yes" ? "YES" : "NO" ) << endl;

    }
    return 0;
}