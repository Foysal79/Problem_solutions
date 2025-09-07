#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        string target = "Timur";
        if(n != 5) 
        {
            cout << "NO" << endl;
            
        }
        else {
            sort(s.begin(), s.end());
        sort(target.begin(), target.end());
        if(s == target)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

        }
        
    }

    return 0;
}