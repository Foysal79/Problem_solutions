#include <bits/stdc++.h>
using namespace std;
int main()
{

   
    int t;
    cin >> t;
    while (t--)
    {
         int sum = 0;
        int x, n;
        cin >> x >> n;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                sum -= x;
            }
            else
            {
                sum += x;
            }
        }
        cout << sum << endl;
    }
    

    return 0;
}