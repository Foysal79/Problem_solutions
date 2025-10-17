#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    long long paired_sum = 0;
    int max_pair_len = 0;
    vector<int> singles;
    for (auto const& [len, count] : counts) {
        if (count >= 2) {
            paired_sum += (long long)(count / 2) * 2 * len;
            max_pair_len = max(max_pair_len, len);
        }
        if (count % 2 == 1) {
            singles.push_back(len);
        }
    }
    sort(singles.rbegin(), singles.rend());
    long long max_perimeter = 0;
    long long S = paired_sum;
    int M = max_pair_len;
    if (S > 0) {
        long long current_perimeter = S;
        long long longest_side = M;
        if (current_perimeter > 2LL * longest_side) {
            max_perimeter = max(max_perimeter, current_perimeter);
        }
    }
    for (int s : singles) {
        long long current_perimeter = S + s;
        long long longest_side = max(M, s);
        if (current_perimeter > 2LL * longest_side) {
            max_perimeter = max(max_perimeter, current_perimeter);
        }
    }

    if (singles.size() >= 2) {
        for (size_t i = 0; i < singles.size() - 1; ++i) {
            int s_i = singles[i];
            int s_j = singles[i + 1];
            long long current_perimeter = S + s_i + s_j;
            long long longest_side = max(M, s_i); 
            if (current_perimeter > 2LL * longest_side) {
                max_perimeter = max(max_perimeter, current_perimeter);
            }
        }
    }

    cout << max_perimeter << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

