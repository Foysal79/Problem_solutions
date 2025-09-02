#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> s1;
    for(char c : s) 
    {
        c = tolower(c);
        s1.push_back(c);
    }
    sort(s1.begin(), s1.end());
    s1.erase(unique(s1.begin(), s1.end()), s1.end());

    if(s1.size() == 26)
    {
     cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}