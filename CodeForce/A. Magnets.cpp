#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int count = 1;
    string str[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] != str[i + 1])
        {
            count += 1;
        }
    }
  cout << count << endl;
    
    return 0;
}
