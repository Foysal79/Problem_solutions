#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_sorted(const vector<int>& arr) {
    for (size_t i = 0; i + 1 < arr.size(); ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> initial_pairs(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
    }

    if (!is_sorted(a) || !is_sorted(b)) {
        cout << 0 << endl;
        return;
    }

    long long ans = 1;
    long long mod = 998244353;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != initial_pairs[i].first) {
            count++;
        }
    }
    
    int i = 0;
    while (i < n) {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[i] && b[j + 1] == b[i]) {
            j++;
        }
        
        int swapped_count = 0;
        for (int k = i; k <= j; ++k) {
            if (a[k] != initial_pairs[k].first) {
                swapped_count++;
            }
        }
        
        if (swapped_count > 0 && swapped_count < (j - i + 1)) {
            ans = (ans * 2) % mod;
        }
        
        i = j + 1;
    }


    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}