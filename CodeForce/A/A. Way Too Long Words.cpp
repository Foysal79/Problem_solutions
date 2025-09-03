#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while(t--)
 {
    string str;
    cin >> str;
    
    int l = str.size();
    if( l > 10)
    {
        cout << str[0] << l-2 << str[l-1] << endl;
    }
    else{
        cout << str << endl;
    }
   


 }

    return 0;
}