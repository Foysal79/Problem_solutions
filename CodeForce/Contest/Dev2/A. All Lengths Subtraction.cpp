#include <bits/stdc++.h>

// Use standard namespace for competitive programming
using namespace std;

// Function to solve a single test case
void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<int> b(k);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];

    // Sort product prices in descending order
    sort(a.rbegin(), a.rend());
    // Sort voucher values in ascending order
    sort(b.begin(), b.end());

    long long total_cost = 0;
    int p_l = 0;      // Pointer for most expensive products
    int p_r = n - 1;  // Pointer for least expensive products
    int b_l = 0;      // Pointer for smallest vouchers (especially size 1)
    int b_r = k - 1;  // Pointer for largest vouchers

    // Process vouchers of size 1 first.
    // Using a b=1 voucher on the most expensive item `a[p_l]` makes it free.
    // It's equivalent to paying for it once. To simplify calculation, we add it twice.
    while (b_l <= b_r && b[b_l] == 1) {
        total_cost += 2 * a[p_l];
        p_l++;
        b_l++;
    }

    // Process vouchers of size > 1, from largest to smallest.
    // For each voucher `v`, we must pay for the most expensive available item `a[p_l]`.
    // The voucher group is formed with `v-1` of the cheapest available items.
    // This makes the cheapest of the group, `a[p_r]`, free.
    // So we pay for `a[p_l]` and `a[p_r]` effectively.
    while (b_l <= b_r) {
        total_cost += a[p_l];
        total_cost += a[p_r];
        p_l++;
        p_r -= (b[b_r] - 1);
        b_r--;
    }

    cout << total_cost << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}
