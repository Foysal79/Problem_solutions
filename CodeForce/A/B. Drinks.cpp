#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double c = 0;
    int original_n = n;
    while(n--)
    {
        int x;
        cin >> x;
        c += x;
    }
    double total = c / original_n;
    cout << fixed << setprecision(12) << total << endl;

}