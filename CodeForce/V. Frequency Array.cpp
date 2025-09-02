#include <bits/stdc++.h>
using namespace std;

int main() {


    int n, m;
    cin >> n>> m;
    int ar[n], f[m] = {0};
    for(int i = 0; i < n; i++)
    {
       cin >> ar[i];
       f[ar[i]-1]++;
    }
    
    for(int i = 0; i < m; i++)
    {
        cout << f[i] << endl;
      
    }
    

    return 0;
}









//* solve useing vector  

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<int> freq(m, 0); // frequency vector for numbers 1 to M

//     for(int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         freq[x-1]++; // increase count for number x
//     }

//     // print frequencies
//     for(int i = 0; i < m; i++) {
//         cout << freq[i] << endl;
//     }

//     return 0;
// }
