#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // sort ovens by descending rate
    sort(a.rbegin(), a.rend());

    long long total_cakes = 0;
    int k = min((long long)n, m);

    for (int i = 0; i < k; ++i) {
        total_cakes += 1LL * a[i] * (m - i);
    }

    cout << total_cakes << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// solve this problem 