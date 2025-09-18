#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> ans;
        long long pow10 = 10; 

        for (int k = 1; k <= 18; k++) {
            long long denom = pow10 + 1; 
            if (denom > n) break; 
            if (n % denom == 0) {
                ans.push_back(n / denom);
            }
            pow10 *= 10;
        }

        if (ans.empty()) {
            cout << 0 << "\n";
        } else {
            sort(ans.begin(), ans.end());
            cout << ans.size();
            for (auto x : ans) cout << " " << x;
            cout << "\n";
        }
    }

    return 0;
}
