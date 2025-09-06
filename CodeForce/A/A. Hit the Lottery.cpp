#include <bits/stdc++.h>
using namespace std;
int main()
{
  
    int n; cin >> n;
    long long c = 0;
    int d[] = {100, 20, 10, 5, 1};
    for(int x : d)
    {
        c += n/x;
        n%= x;
    }

    cout << c << endl;
    return 0;
}