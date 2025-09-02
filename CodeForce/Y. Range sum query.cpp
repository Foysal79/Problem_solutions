#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
   long long int ar[n+1];

   for(int i = 1; i <= n; i++)
   {
   cin >> ar[i];
   }
   

   while(m--)
   {
    int x, y;
    cin >> x >> y;
    long long sum = 0;
    for(int i = x; i <= y; i++)
    {
        sum += ar[i];
    }
    cout << sum << endl;
   
   }


    return 0;
}
