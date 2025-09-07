#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;

    // We store pairs of (b[i], i) to keep the original indices
    // after sorting based on the b[i] values.
    std::vector<std::pair<int, int>> b_indexed(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b_indexed[i].first;
        b_indexed[i].second = i;
    }

    // Sort by the b_i values. This step groups all indices
    // that have the same b_i value together.
    std::sort(b_indexed.begin(), b_indexed.end());

    // --- Validation Phase ---
    // We iterate through the sorted groups to check if a solution is possible.
    bool possible = true;
    for (int i = 0; i < n; ) {
        int j = i;
        // Find the end of the current group of identical b_i values.
        while (j < n && b_indexed[j].first == b_indexed[i].first) {
            j++;
        }
        
        // The current group of indices is from i to j-1.
        int group_size = j - i;
        int b_value = b_indexed[i].first;

        // The core validation check: for any value b_i, its frequency
        // (group_size) must be divisible by the value itself.
        if (group_size % b_value != 0) {
            possible = false;
            break;
        }

        // Move the pointer to the start of the next group.
        i = j;
    }

    if (!possible) {
        std::cout << -1 << "\n";
        return;
    }

    // --- Construction Phase ---
    // If validation passed, a solution is guaranteed to exist.
    std::vector<int> a(n);
    int assigned_value_counter = 1; // This counter provides unique values for our array 'a'.

    for (int i = 0; i < n; ) {
        int j = i;
        // Find the end of the current group.
        while (j < n && b_indexed[j].first == b_indexed[i].first) {
            j++;
        }
        
        int b_value = b_indexed[i].first;
        int group_start_index = i;

        // Iterate through the indices of the current group to assign values.
        for(int k = group_start_index; k < j; ++k) {
            // Get the original index from before sorting.
            int original_index = b_indexed[k].second;
            
            // Assign a value to a[original_index].
            // Integer division (k - group_start_index) / b_value creates
            // sub-groups of size b_value. Each sub-group gets a unique value.
            int sub_group_id = (k - group_start_index) / b_value;
            a[original_index] = assigned_value_counter + sub_group_id;
        }
        
        // The number of unique values we used for this group.
        int num_sub_groups = (j - group_start_index) / b_value;
        assigned_value_counter += num_sub_groups;

        // Move to the next group.
        i = j;
    }

    // Print the final constructed array 'a'.
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O for performance.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}