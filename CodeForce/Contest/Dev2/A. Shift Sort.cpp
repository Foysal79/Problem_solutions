#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // 1. Count the total number of '0's.
    int zero_count = 0;
    for (char c : s) {
        if (c == '0') {
            zero_count++;
        }
    }

    if (zero_count == 0 || zero_count == n) {
        // The string is already sorted if it contains all '0's or all '1's.
        std::cout << 0 << std::endl;
        return;
    }

    // 2. Count the number of '1's in the positions that should be '0's.
    // These are the first 'zero_count' positions.
    int misplaced_ones = 0;
    for (int i = 0; i < zero_count; ++i) {
        if (s[i] == '1') {
            misplaced_ones++;
        }
    }

    // 3. The answer is the number of misplaced '1's.
    std::cout << misplaced_ones << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}