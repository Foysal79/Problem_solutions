#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t; cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin, s);
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(i == 0)
            {
                ans.push_back(s[i]);
            }
            else if(s[i] == ' ' && i + 1 < s.size())
            {
                ans.push_back(s[i+1]);
            }
        }
        cout << ans << endl;
    }


    return 0;
}