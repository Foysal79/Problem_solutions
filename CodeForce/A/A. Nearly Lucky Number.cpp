#include <bits/stdc++.h>
using namespace std;
bool isLucky(int x)
{
    if(x == 0) return false;
    while(x > 0)
    {
        int d = x % 10;
        if(d != 7 && d != 4)
        {
            return false;
        }
        x /= 10;
        
    }
    return true;
}
int main()
{

    long long int n;
    cin >> n;

    int count = 0;
    while(n > 0)
    {
        int d = n % 10;
        if(d == 7 || d == 4 )
        {
            count++;
        }
        n = n / 10;
    }

    if(isLucky(count))
    {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }


    return 0;

}