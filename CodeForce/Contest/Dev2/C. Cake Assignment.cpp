#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k, x;
    cin >> k >> x;

    long long initial_c = 1LL << k;        // Chocola’s initial cakes = 2^k
    long long total = 1LL << (k + 1);      // Total cakes = 2^(k+1)

    if (x == initial_c) {
        cout << 0 << "\n\n";
        return;
    }

    vector<int> backward_ops;
    long long current_x = x;

    while (current_x != initial_c) {
        if (current_x < initial_c) {
            long long prev_c = 2 * current_x;
            backward_ops.push_back(1);
            current_x = prev_c;
        } else {
            long long prev_c = 2 * current_x - total;
            backward_ops.push_back(2);
            current_x = prev_c;
        }
    }

    reverse(backward_ops.begin(), backward_ops.end());

    cout << backward_ops.size() << "\n";
    for (size_t i = 0; i < backward_ops.size(); ++i) {
        cout << backward_ops[i] << (i + 1 == backward_ops.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}