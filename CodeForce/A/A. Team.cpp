// https://codeforces.com/contest/231/problem/A
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, total_solution = 0;
    cin >> n;
    while (n > 0)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x + y + z >= 2)
            total_solution += 1;
        n--;
    }
    cout << total_solution << endl;

    return 0;
}