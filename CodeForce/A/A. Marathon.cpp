#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    int count = 0;
    while (t--)
    {
        int count = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b)
        {
            count += 1;
        }
        if (a < c)
        {
            count += 1;
        }
        if (a < d)
        {
            count += 1;
        }
        cout << count << endl;
    }

    return 0;
}