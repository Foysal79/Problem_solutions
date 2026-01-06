#include <bits/stdc++.h>
using namespace std;

void solve_test_case() {
    long long n; 
    cin >> n;

    long long total_eaten_by_hao = 0;

    
    while (n >= 3) {
        
        long long eats_now = n / 3;
        total_eaten_by_hao += eats_now;

       
        n = n - 2 * eats_now;
    }

    cout << total_eaten_by_hao << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    
    while (t--) {
        solve_test_case();
    }

    return 0;
}

