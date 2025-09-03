#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int positions = 0;
    if(n < 5)
    {
        positions += 1;
    }
    else{
        positions += n / 5;
        if(n % 5 > 0)
        {
            positions += 1;
        }
    }

    cout << positions << endl;


    return 0;
}