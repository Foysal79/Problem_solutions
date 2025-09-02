#include <bits/stdc++.h>
using namespace std;
int main()
{
 
    int t;
    cin >> t;
    while(t--)
    {

        int n;
        cin >> n;
        int ar[n];
        for(int i = 1; i <= n; i++)
        {
            cin >> ar[i];
        }
        
        int sum = INT_MAX;
        for(int i = 1; i <= n-1; i++)
        {
            for(int j = i+1; j <= n ; j++)
            {
                int total = ar[i] + ar[j] + j - i;
                if(sum > total)
                {
                    sum = total;
                }
            }
        }

        cout << sum << endl;

    }

    return 0;
}