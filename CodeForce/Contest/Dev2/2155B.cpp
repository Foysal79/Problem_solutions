#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        
        // Maximum escape cells = 4n - 4 (boundary cells)
        if (k > 4 * n - 4) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<string> grid(n, string(n, 'L'));
        int cnt = 0;

        // Fill top row with 'U'
        for (int j = 0; j < n && cnt < k; j++) {
            grid[0][j] = 'U'; cnt++;
        }

        // Fill bottom row with 'D'
        for (int j = 0; j < n && cnt < k; j++) {
            grid[n-1][j] = 'D'; cnt++;
        }

        // Fill left column with 'L'
        for (int i = 1; i < n-1 && cnt < k; i++) {
            grid[i][0] = 'L'; cnt++;
        }

        // Fill right column with 'R'
        for (int i = 1; i < n-1 && cnt < k; i++) {
            grid[i][n-1] = 'R'; cnt++;
        }

        // Print grid
        for (auto &row : grid) cout << row << "\n";
    }
    return 0;
}
