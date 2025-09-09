#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to solve a single test case for the Cake Assignment problem.
void solve() {
    long long k, x;
    std::cin >> k >> x;

    // The initial state is that both Chocola and Vanilla have 2^k cakes.
    long long initial_c = 1LL << k;
    // The total number of cakes is 2 * 2^k = 2^(k+1), which is constant.
    long long total = 1LL << (k + 1);

    // If Chocola already has the target number of cakes, no operations are needed.
    if (x == initial_c) {
        std::cout << 0 << '\n';
        std::cout << '\n';
        return;
    }

    // We work backward from the target state (Chocola has x cakes)
    // to the initial state (Chocola has 2^k cakes).
    std::vector<int> backward_ops;
    long long current_x = x;

    while (current_x != initial_c) {
        // At any state `current_x`, the previous state `C_prev` must be one of two candidates:
        // 1. `2 * current_x` (reversing Op 1)
        // 2. `2 * current_x - total` (reversing Op 2)
        // The choice between them is uniquely determined by comparing `current_x` to `initial_c`.

        if (current_x < initial_c) {
            // If current_x < 2^k, the only valid predecessor is 2 * current_x.
            // This means the forward operation was `C_prev -> C_prev / 2`, which is Op 1.
            long long prev_c = 2 * current_x;
            backward_ops.push_back(1);
            current_x = prev_c;
        } else { // current_x > initial_c
            // If current_x > 2^k, the only valid predecessor is 2 * current_x - total.
            // This means the forward operation was `C_prev -> (C_prev + total) / 2`, which is Op 2.
            long long prev_c = 2 * current_x - total;
            backward_ops.push_back(2);
            current_x = prev_c;
        }
    }

    // The `backward_ops` vector contains the sequence of operations in reverse order.
    // We reverse it to get the correct forward sequence for the output.
    std::reverse(backward_ops.begin(), backward_ops.end());

    std::cout << backward_ops.size() << '\n';
    for (size_t i = 0; i < backward_ops.size(); ++i) {
        std::cout << backward_ops[i] << (i == backward_ops.size() - 1 ? "" : " ");
    }
    std::cout << '\n';
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}