#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin >> s;
    int n = s.size(), p = 0;
    int ar[n];
    for(int i = 0 ; i < n; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            ar[p++] = s[i] - '0';  // character to integer convert 
        }
    }
    sort(ar, ar + p);
    for(int i = 0; i < p; i++)
    {
        cout << ar[i] ;
        if(i != p - 1)
        {
            cout << "+" ;
        }
    }

    return 0;
}