#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    int max_idx = -1; 
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        if (p[i] == n)
        {
            max_idx = i;
        }
    }
    bool is_possible = true;
    for (int i = 1; i <= max_idx; ++i)
    {
        if (p[i] < p[i - 1])
        {
            is_possible = false;
            break;
        }
    }
    if (!is_possible)
    {
        cout << "NO\n";
        return;
    }
    for (int i = max_idx + 1; i < n; ++i)
    {
        if (p[i] > p[i - 1])
        {
            is_possible = false;
            break;
        }
    }
    if (is_possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 
    while (t--)
    {
        solve();
    }

    return 0;
}