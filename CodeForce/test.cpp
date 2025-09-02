#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];

        long long ans = LLONG_MAX;

        for(int start = 0; start < n; start++) {
            vector<long long> tmp = h;
            long long attacks = 0;
            // damage start from mob `start`
            attacks += tmp[start];
            tmp[start] = 0;

            // simulate left part (circular)
            for(int i = (start + 1) % n; i != start; i = (i + 1) % n) {
                long long prev = tmp[(i-1+n)%n];
                long long dmg_needed = max(0LL, tmp[i]-prev);
                attacks += dmg_needed;
                tmp[i] -= dmg_needed;
            }
            ans = min(ans, attacks);
        }

        cout << ans << "\n";
    }

    return 0;
}
