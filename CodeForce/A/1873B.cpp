#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long int cal = 1;
        cin >> n;
        vector<int> v(n);

        for (int &c : v)
        {
            cin >> c;
        }
        auto it = min_element(v.begin(), v.end());
        int index = distance(v.begin(), it);
        for (int i = 0; i < n; i++)
        {
            if (i == index)
            {
                cal *= (v[i] + 1);
            }
            else
                cal *= v[i];
        }
        cout << cal << endl;
    }

    return 0;
}