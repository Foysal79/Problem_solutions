#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    int s = 0, d = 0, l = 0 , r = n - 1;
    bool SerejaTerm = true;
    while(l <= r){
        int choice;
        if(ar[l] > ar[r])
        {
            choice = ar[l];
            l++;
        }
        else{
            choice = ar[r];
            r--;
        }
        if(SerejaTerm){
            s += choice;
        }
        else{
            d += choice;
        }
        SerejaTerm = !SerejaTerm;
    }
    cout << s << " " << d << endl;


    
    return 0;
}