#include <bits/stdc++.h>
using namespace std;

// Function to solve a single test case
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    // prefix_sum[i] will store the sum of the first i elements of 'a'
    vector<long long> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    // Iterate through all possible first cut points 'l'
    // 'l' is the 1-based index of the end of the prefix
    for (int l = 1; l <= n - 2; ++l)
    {
        // Iterate through all possible second cut points 'r'
        // 'r' is the 1-based index of the end of the middle part
        for (int r = l + 1; r <= n - 1; ++r)
        {

            // Calculate sums of the three parts using the prefix sum array
            // Part 1: a[0]...a[l-1]
            long long sum1 = prefix_sum[l];
            // Part 2: a[l]...a[r-1]
            long long sum2 = prefix_sum[r] - prefix_sum[l];
            // Part 3: a[r]...a[n-1]
            long long sum3 = prefix_sum[n] - prefix_sum[r];

            // Calculate the remainders modulo 3
            int s1 = sum1 % 3;
            int s2 = sum2 % 3;
            int s3 = sum3 % 3;

            // Check if the condition is met:
            // 1. All remainders are the same
            bool all_same = (s1 == s2 && s2 == s3);
            // 2. All remainders are different (i.e., a permutation of 0, 1, 2)
            bool all_different = (s1 != s2 && s1 != s3 && s2 != s3);

            if (all_same || all_different)
            {
                // If a solution is found, print it and exit the function for this test case
                cout << l << " " << r << endl;
                return;
            }
        }
    }

    // If the loops complete without finding a solution, output "0 0"
    cout << "0 0" << endl;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}