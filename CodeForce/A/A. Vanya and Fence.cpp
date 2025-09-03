// problem : https://codeforces.com/contest/677/problem/A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, h, sum = 0;
    cin >> n >> h;
    while (n > 0)
    {
        int x;
        cin >> x;
        if (x > h)
            sum += 2;
        else
            sum += 1;
        n -= 1;
    }
    cout << sum << endl;
    return 0;
}