#include <bits/stdc++.h>
using namespace std;
bool isDistinct(int x)
{
    string s = to_string(x);
    set<char> st(s.begin(), s.end());
    return st.size() == s.size();
}
int main()
{
     int n;
     cin >> n;

     while(1)
     {
        n++;
        if(isDistinct(n))
        {
            cout << n << endl;
            break;
        }
     }

    return 0;
}