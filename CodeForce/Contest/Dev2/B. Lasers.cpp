#include <iostream>
#include <vector>

using namespace std;
void solve() {
    int n, m;
    long long x, y;

    cin >> n >> m >> x >> y;
    long long laser_pos;
    for (int i = 0; i < n; ++i) {
        cin >> laser_pos;
    }
    for (int i = 0; i < m; ++i) {
        cin >> laser_pos;
    }
    cout << n + m << endl;
}

int main() {
    // Fast I/O for performance in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}