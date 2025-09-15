#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int fsum = 0, ssum = 0;
        vector<int> v;

        for (char c : s)
        {
            v.push_back(c - '0');
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (i <= 2)
            {
                fsum += v[i];
            }
            if (i >= 3)
            {
                ssum += v[i];
            }
        }
        if (fsum == ssum)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}