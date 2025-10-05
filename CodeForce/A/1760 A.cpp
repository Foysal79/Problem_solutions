#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        int medium; 
        cin >> a >> b >> c;
        if ((a > b && a < c) || (a < b && a > c))
        {
            medium = a;
        }
        else if ((b > a && b < c) || (b < a && b > c))
        {
            medium = b;
        }
        else
        {
           medium = c;
        }

        cout << medium << endl;
    }

    return 0;
}