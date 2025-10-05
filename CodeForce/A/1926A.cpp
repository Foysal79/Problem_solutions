#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int freq[26] = {0};

        for (char c : s)
        {
            freq[c - 'A']++;
        }

        // for (int i = 0; i < 26; i++)
        // {
        //     if (freq[i] > 0)
        //     {
        //         cout << char('A' + i) << " : " << freq[i] << endl;
        //     }
        // }

        if (freq['A' - 'A'] > freq['B' - 'A'])
        {
            cout << "A\n";
        }
        else
            cout << "B\n";
    }
    return 0;
}