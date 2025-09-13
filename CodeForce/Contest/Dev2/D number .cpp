#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    long long total_dandelions = 0;
    long long min_odd_dandelions = numeric_limits<long long>::max();
    int odd_field_count = 0;

    for (int i = 0; i < n; ++i)
    {
        long long a;
        cin >> a;
        total_dandelions += a;

        
        if (a % 2 != 0)
        {
            odd_field_count++;
            min_odd_dandelions = min(min_odd_dandelions, a);
        }
    }


    if (odd_field_count == 0)
    {
        cout << 0 << endl;
        return;
    }


    if (odd_field_count % 2 != 0)
    {
        cout << total_dandelions << endl;
        return;
    }

   
    if (odd_field_count % 2 == 0)
    {
        cout << total_dandelions - min_odd_dandelions << endl;
        return;
    }
}

int main()
{
    // Fast I/O for performance
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
