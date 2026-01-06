#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> counts(n + 1, 0);
    vector<int> prefix_counts(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    for (int i = 1; i <= n; ++i) {
        prefix_counts[i] = prefix_counts[i - 1] + counts[i];
    }

    int max_beauty = 1; 

    for (int d = n; d >= 2; --d) {
        long long erase_cost = 0;

        long long multiples_count = 0;
        if (d <= n) {
            multiples_count += counts[d];
        }
        if (2 * d <= n) {
            multiples_count += counts[2 * d];
        }
        if (3 * d <= n) {
            multiples_count += counts[3 * d];
        }

        
        int upper_bound = n;
        
        if (4LL * d - 1 < n) {
            upper_bound = 4 * d - 1;
        }

        long long total_in_range = prefix_counts[upper_bound];

        
        erase_cost = total_in_range - multiples_count;

        if (erase_cost <= k) {
            max_beauty = d;
            break; 
        }
    }

    cout << max_beauty << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
