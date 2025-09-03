#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string a, b, c;

        cin >> n >> a;
        cin >> m >> b;
        cin >> c;

        string result = a;

        for (int i = 0; i < m; i++)
        {
            if (c[i] == 'V')
            {
                result = b[i] + result; // Vlad → সামনে যোগ করবে
            }
            else
            {
                result = result + b[i]; // Dima → পেছনে যোগ করবে
            }
        }

        cout << result << "\n";
    }
    return 0;
}
