#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve a single test case
void solve()
{
    long long n;
    long long m;
    cin >> n >> m;

    vector<pair<long long, long long>> requirements(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> requirements[i].first >> requirements[i].second;
    }

    // Add the starting point (time 0, side 0) to the list of requirements
    // to handle the first segment uniformly.
    requirements.insert(requirements.begin(), {0, 0});

    long long total_score = 0;

    // Process the segments between consecutive requirements
    for (size_t i = 0; i < n; ++i)
    {
        long long t1 = requirements[i].first;
        long long s1 = requirements[i].second;
        long long t2 = requirements[i + 1].first;
        long long s2 = requirements[i + 1].second;

        // The logic relies on the parity of (time - side).
        // If the parity is the same for the start and end of a segment,
        // it's possible to connect them with a path of only "run" actions,
        // maximizing the score for that segment.
        if (((t1 - s1) % 2 + 2) % 2 == ((t2 - s2) % 2 + 2) % 2)
        {
            // A special case: if t-s is identical, it means side changes perfectly
            // match time changes. A pure run path is not just possible, but required.
            if (t1 - s1 == t2 - s2)
            {
                total_score += (t2 - t1);
            }
            else
            {
                // If parities match but t-s values differ, we can still gain points.
                // The score is half the difference of the time and side differences.
                total_score += ((t2 - t1) - (s2 - s1)) / 2;
            }
        }
    }

    // After the last requirement, Farmer John can run freely until time m.
    // The score for this final stretch depends on the last segment that had
    // a consistent (t-s) parity.

    long long last_req_t = requirements.back().first;
    long long last_req_s = requirements.back().second;

    long long last_parity_val = last_req_t - last_req_s;

    // Find the beginning of the last same-parity block to determine the true
    // starting point for the final optimal run.
    long long block_start_t = requirements[0].first;
    long long block_start_s = requirements[0].second;

    for (size_t i = 0; i < requirements.size() - 1; ++i)
    {
        long long t1 = requirements[i].first;
        long long s1 = requirements[i].second;
        long long t2 = requirements[i + 1].first;
        long long s2 = requirements[i + 1].second;

        // If parity changes, the block is broken. Start a new one.
        if (((t1 - s1) % 2 + 2) % 2 != ((t2 - s2) % 2 + 2) % 2)
        {
            block_start_t = t2;
            block_start_s = s2;
        }
    }

    // The final score calculation combines the base score with the maximum
    // possible points from the last consistent block to the end time m.
    total_score += (m - last_req_t + last_req_s - ((block_start_t - block_start_s) % 2 + 2) % 2) / 2;

    cout << total_score << endl;
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