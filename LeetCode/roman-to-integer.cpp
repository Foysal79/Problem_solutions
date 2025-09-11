#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();

    int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 ;

    int i = 0, c = 0;
    while(i < n)
    {
        if(s[i] == 'I' && s[i+1] == 'V')
        {
            c += 4;
            i += 2;
        }
        if(s[i] == 'I' && s[i+1] == 'X')
        {
            c += 9;
            i += 2;
        }
    }

    return 0;
}