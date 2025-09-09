#include <iostream>

void solve() {
    long long x;
    std::cin >> x;
    // As proven in the logic, y = 2x is always a valid solution.
    long long y = 2 * x;
    std::cout << y << std::endl;
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