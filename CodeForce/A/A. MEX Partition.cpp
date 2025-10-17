#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, mx = 0, a;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
       if(mx <= a)
       {
        mx = a;
       }
    }
    cout << mx << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}