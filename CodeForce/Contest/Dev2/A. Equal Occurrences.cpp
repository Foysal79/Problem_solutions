#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

struct Constraint
{
    int k, l, r;
    int original_idx;
};

bool compareConstraints(const Constraint &a, const Constraint &b)
{
    if (a.k != b.k)
    {
        return a.k < b.k;
    }
    return a.original_idx < b.original_idx;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Constraint> initial_constraints(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> initial_constraints[i].k >> initial_constraints[i].l >> initial_constraints[i].r;
        initial_constraints[i].original_idx = i;
    }

    sort(initial_constraints.begin(), initial_constraints.end(), compareConstraints);

    vector<Constraint> constraints;
    if (m > 0)
    {
        constraints.push_back(initial_constraints[0]);
        for (int i = 1; i < m; ++i)
        {
            if (initial_constraints[i].k == constraints.back().k)
            {
                constraints.back().l = max(constraints.back().l, initial_constraints[i].l);
                constraints.back().r = min(constraints.back().r, initial_constraints[i].r);
            }
            else
            {
                constraints.push_back(initial_constraints[i]);
            }
        }
    }
    m = constraints.size();

    vector<map<vector<int>, long long>> dp(n);

    if (m > 0)
    {
        vector<int> s(m);
        for (int j = 0; j < m; ++j)
        {
            if (0 <= constraints[j].k)
            {
                s[j] = 1;
            }
        }
        if (all_of(s.begin(), s.end(), [&](int val)
                   {
            bool ok = true;
            for(size_t i = 0; i < constraints.size(); ++i) {
                if (s[i] > constraints[i].r) ok = false;
            }
            return ok; }))
        {
            dp[0][s] = n;
        }
    }
    else
    {
        dp[0][{}] = n;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int b = 0; b < i; ++b)
        {
            if (dp[b].count(i - 1))
            {
                for (auto const &[s_prev, count] : dp[b][i - 1])
                {
                    // Transition to b' = b
                    if (n - 1 - i - b >= 0)
                    {
                        vector<int> s_new = s_prev;
                        for (int j = 0; j < m; ++j)
                        {
                            if (b <= constraints[j].k)
                            {
                                s_new[j]++;
                            }
                        }
                        bool possible = true;
                        for (int j = 0; j < m; ++j)
                        {
                            if (s_new[j] > constraints[j].r)
                            {
                                possible = false;
                                break;
                            }
                        }
                        if (possible)
                        {
                            long long ways = (long long)(n - 1 - i - b);
                            dp[b][i][s_new] = (dp[b][i][s_new] + count * ways) % MOD;
                        }
                    }

                    // Transition to b' = b + 1
                    if (b + 1 < n)
                    {
                        vector<int> s_new = s_prev;
                        for (int j = 0; j < m; ++j)
                        {
                            if (b + 1 <= constraints[j].k)
                            {
                                s_new[j]++;
                            }
                        }
                        bool possible = true;
                        for (int j = 0; j < m; ++j)
                        {
                            if (s_new[j] > constraints[j].r)
                            {
                                possible = false;
                                break;
                            }
                        }
                        if (possible)
                        {
                            long long ways = (long long)(b + 1);
                            dp[b + 1][i][s_new] = (dp[b + 1][i][s_new] + count * ways) % MOD;
                        }
                    }
                }
            }
        }
    }

    if (m == 0)
    {
        long long total_perms = 1;
        for (int i = 1; i <= n; ++i)
        {
            total_perms = (total_perms * i) % MOD;
        }
        if (n > 10000)
        { // Factorial for large N is complex, but for m=0 it simplifies
            long long ans = 1;
            for (int i = 0; i < n; ++i)
                ans = (ans * (n - i)) % MOD;
            cout << ans << endl;
            return;
        }
    }

    long long total_count = 0;
    for (int b = 0; b < n; ++b)
    {
        if (dp[b].count(n - 1))
        {
            for (auto const &[s, count] : dp[b][n - 1])
            {
                bool ok = true;
                for (int j = 0; j < m; ++j)
                {
                    if (s[j] < constraints[j].l)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    total_count = (total_count + count) % MOD;
                }
            }
        }
    }

    // A special case for n=1
    if (n == 1)
    {
        bool ok = true;
        for (int j = 0; j < m; ++j)
        {
            if (constraints[j].l > 1 || constraints[j].r < 1)
            {
                if (constraints[j].k >= 0)
                    ok = false;
            }
        }
        total_count = ok ? 1 : 0;
    }

    cout << total_count << endl;
}

int main()
{
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
