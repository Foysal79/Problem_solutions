#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long ar[n];
    int operation = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];

    }

    
    while(true)
    {
        bool allEven = true;
        for(int i = 0; i < n; i++)
        {
            if(ar[i] % 2 != 0)
            {
                allEven = false;
                break;
            }
        }
        if(!allEven) break;

        for(int i = 0; i < n; i++)
        {
          ar[i] /= 2;
        }
        operation++;
    }


    cout << operation << endl;




    return 0;

}