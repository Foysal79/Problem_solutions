#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> f(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i];
    }

    // Step 1 & 2: Calculate frequencies for P and construct P
    std::vector<int> p_candidate;
    
    // Count for number 1
    long long count_p_1 = f[0] - n;
    for (int i = 0; i < count_p_1; ++i) {
        p_candidate.push_back(1);
    }

    // Counts for numbers > 1
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < f[i]; ++j) {
            p_candidate.push_back(i + 1);
        }
    }

    // Basic sanity check: if the size isn't N, something is wrong with the input constraints.
    if (p_candidate.size() != n) {
        std::cout << -1 << std::endl;
        return;
    }

    // Step 3: Construct candidate array A
    std::vector<int> a_candidate(n);
    if (n > 0) {
        a_candidate[0] = p_candidate[0];
        for (int i = 1; i < n; ++i) {
            if (p_candidate[i] > p_candidate[i - 1]) {
                a_candidate[i] = p_candidate[i];
            } else {
                a_candidate[i] = 1; // Simplest choice to keep prefix max the same
            }
        }
    }

    // Step 4: Verification
    // Calculate P and S from a_candidate
    if (n == 0) { // Handle edge case of N=0
        std::cout << std::endl;
        return;
    }

    std::vector<int> p_actual(n);
    p_actual[0] = a_candidate[0];
    for(int i = 1; i < n; ++i) {
        p_actual[i] = std::max(p_actual[i-1], a_candidate[i]);
    }

    std::vector<int> s_actual(n);
    s_actual[n-1] = a_candidate[n-1];
    for(int i = n-2; i >= 0; --i) {
        s_actual[i] = std::min(s_actual[i+1], a_candidate[i]);
    }

    // Calculate F_actual from P_actual and S_actual
    std::vector<long long> f_actual(n, 0);
    for (int val : p_actual) {
        if (val >= 1 && val <= n) {
            f_actual[val - 1]++;
        }
    }
    for (int val : s_actual) {
         if (val >= 1 && val <= n) {
            f_actual[val - 1]++;
        }
    }

    // Step 5 & 6: Compare and print
    if (f_actual == f) {
        for (int i = 0; i < n; ++i) {
            std::cout << a_candidate[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
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
