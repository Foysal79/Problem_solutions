#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;
    int count = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target = a[k - 1];
    
    for(int x : a)
    {
        if(x >= target && x > 0)
        {
            count += 1;
        }
    }
    cout << count << endl;


    return 0;
}
