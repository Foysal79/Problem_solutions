#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief Gets the position of the most significant bit (MSB).
 * * This function calculates the 0-indexed position of the highest set bit.
 * It uses the __builtin_clz (count leading zeros) intrinsic for efficiency.
 * For a 32-bit integer, the MSB position is 31 minus the number of leading zeros.
 * * @param n The integer to analyze. Must be positive.
 * @return The 0-indexed position of the MSB.
 */
int get_msb_pos(int n)
{
    // This is a GCC/Clang specific intrinsic. For other compilers,
    // a loop-based or log2-based approach might be needed.
    // E.g., return static_cast<int>(log2(n));
    return 31 - __builtin_clz(n);
}

// Function to solve a single test case
void solve()
{
    int a, b;
    std::cin >> a >> b;

    // Case 1: a is already equal to b. 0 operations needed.
    if (a == b)
    {
        std::cout << 0 << std::endl
                  << std::endl;
        return;
    }

    // Case 2: a is less than b.
    if (a < b)
    {
        // The MSB position can never increase. So if b's MSB is higher, it's impossible.
        if (get_msb_pos(a) < get_msb_pos(b))
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            // If MSB(a) == MSB(b), a 1-step solution always exists.
            // The value of x will be a ^ b, which can be proven to be <= a.
            std::cout << 1 << std::endl;
            std::cout << (a ^ b) << std::endl;
        }
    }
    else
    { // Case 3: a is greater than b.
        // First, check if a 1-operation solution exists.
        int x = a ^ b;
        if (x <= a)
        {
            std::cout << 1 << std::endl;
            std::cout << x << std::endl;
        }
        else
        {
            // If 1-op fails, a 2-operation solution is always possible.
            // We use (a|b) as a reliable intermediate value.
            // Step 1: a -> (a|b). The required x1 is a ^ (a|b).
            int x1 = a ^ (a | b);
            int intermediate_val = a ^ x1; // This is now equal to (a|b)

            // Step 2: (a|b) -> b. The required x2 is (a|b) ^ b.
            int x2 = intermediate_val ^ b;

            std::cout << 2 << std::endl;
            std::cout << x1 << " " << x2 << std::endl;
        }
    }
}

int main()
{
    // Fast I/O
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
