#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> rounds;
        int multiplier = 1;

        // Extract each digit and make it a round number
        while (n > 0)
        {
            int digit = n % 10;
            if (digit != 0)
            {
                rounds.push_back(digit * multiplier);
            }
            n /= 10;
            multiplier *= 10;
        }

        // Output result
        cout << rounds.size() << "\n";
        for (int r : rounds)
        {
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}
