#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;

    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }
    vector<int> frequencies;
    for (auto const& pair : counts) {
        frequencies.push_back(pair.second);
    }

    int max_length = 0;

    for (int k = 1; k <= n; ++k) {
        int distinct_elements_count = 0;

        for (int freq : frequencies) {
            if (freq >= k) {
                distinct_elements_count++;
            }
        }

        int current_length = k * distinct_elements_count;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }
    cout << max_length << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

