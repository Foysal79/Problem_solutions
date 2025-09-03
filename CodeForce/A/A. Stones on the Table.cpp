#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string str;
    cin >> n >> str;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            count += 1;
        }
    }

    cout << count << endl;

    return 0;
}