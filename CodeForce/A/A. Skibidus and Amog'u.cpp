#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    while(n--)
    {
        string str, strC;
        cin >> str;
        
        str.pop_back();
        str.pop_back();
        str += 'i';

        cout << str << endl;

    }


    return 0;
}