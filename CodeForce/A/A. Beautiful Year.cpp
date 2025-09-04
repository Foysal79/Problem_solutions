#include <bits/stdc++.h>
using namespace std;
bool isDistinct(int x)
{
    int f[10] = {0};
    while (x > 0)
    {
        int d = x % 10;
        if (f[d])
        {
            return false;
        }
        f[d] = 1;
        x /= 10;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;

    while (1)
    {
        n++;
        if (isDistinct(n))
        {
            cout << n << endl;
            break;
        }
    }

    return 0;
}