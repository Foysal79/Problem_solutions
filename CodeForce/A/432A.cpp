#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, time;
    cin >> n >> time;
    int c = 0;
    while (n--)
    {
        int x;
        cin >> x;
        if (x + time <= 5)
        {
            c++;
        }
    }
    cout << c / 3 << endl;

    return 0;
}