#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// sum of digits from 1 to N
ll sumDigitsUpTo(ll N) {
    if (N <= 0) return 0;
    ll res = 0;
    ll factor = 1;
    while (factor <= N) {
        ll lower = N % factor;
        ll cur = (N / factor) % 10;
        ll higher = N / (factor * 10);

        res += higher * 45LL * factor;
        res += (cur * (cur - 1) / 2) * factor;
        res += cur * (lower + 1);

        if (factor > LLONG_MAX / 10) break;
        factor *= 10;
    }
    return res;
}

// sum of digits from L to R
ll sumDigitsRange(ll L, ll R) {
    if (R < L) return 0;
    return sumDigitsUpTo(R) - sumDigitsUpTo(L - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<ll> pow10(20, 1);
    for (int i = 1; i < 20; i++) pow10[i] = pow10[i - 1] * 10LL;

    while (t--) {
        ll k;
        cin >> k;
        ll ans = 0;
        ll rem = k;

        for (int d = 1; rem > 0 && d <= 18; d++) {
            ll L = pow10[d - 1];
            ll cnt = 9 * L;
            ll blockDigits = cnt * d;

            if (rem >= blockDigits) {
                ll R = L + cnt - 1;
                ans += sumDigitsRange(L, R);
                rem -= blockDigits;
            } else {
                ll fullNumbers = rem / d;
                int takeDigits = rem % d;

                if (fullNumbers > 0) {
                    ll R = L + fullNumbers - 1;
                    ans += sumDigitsRange(L, R);
                }
                if (takeDigits > 0) {
                    ll num = L + fullNumbers;
                    // first `takeDigits` digits of num
                    ll divisor = pow10[d - takeDigits];
                    ll leading = num / divisor;
                    while (leading > 0) {
                        ans += leading % 10;
                        leading /= 10;
                    }
                }
                rem = 0;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
