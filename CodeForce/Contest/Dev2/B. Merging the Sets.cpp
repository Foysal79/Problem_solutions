#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

void solve()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // pos[v] will store the final 1-based position (rank) of value v
    std::vector<int> pos(n + 1);

    std::vector<int> stable_vals;
    std::vector<int> unstable_vals;

    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] == '1')
        {
            stable_vals.push_back(i);
        }
        else
        {
            unstable_vals.push_back(i);
        }
    }

    // Assign ranks k+1 to n to stable values, sorted by value.
    int current_rank = unstable_vals.size() + 1;
    for (int val : stable_vals)
    {
        pos[val] = current_rank++;
    }

    // Assign ranks 1 to k to unstable values.
    current_rank = 1;
    // We group unstable values into chunks that fall between stable values.
    int last_stable = 0;
    stable_vals.push_back(n + 1); // Sentinel value

    for (int next_stable : stable_vals)
    {
        std::vector<int> chunk;
        for (int unstable_val : unstable_vals)
        {
            if (unstable_val > last_stable && unstable_val < next_stable)
            {
                chunk.push_back(unstable_val);
            }
        }

        if (!chunk.empty())
        {
            // To make all values in the chunk {j, j+1, ..., l} unstable,
            // we can assign their ranks to create the permutation pattern (j+1, ..., l, j).
            for (size_t i = 0; i < chunk.size() - 1; ++i)
            {
                pos[chunk[i]] = current_rank + i + 1;
            }
            pos[chunk.back()] = current_rank;
            current_rank += chunk.size();
        }
        last_stable = next_stable;
    }

    std::cout << "YES\n";
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        p[pos[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        std::cout << p[i] << (i == n ? "" : " ");
    }
    std::cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
