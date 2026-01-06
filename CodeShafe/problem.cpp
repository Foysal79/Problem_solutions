#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  while(n--)
  {
    int k;
    cin >> k;
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < k; i+= 2)
    {
        char a = s[i];
        char b = s[i+1];
        if(a == '0' && b == '0') ans += 'A';
        else if (a == '0' && b == '1') ans += 'T';
        else if (a == '1' && b == '0') ans += 'C';
        else ans += 'G';
    }
    cout << ans << endl;
  }
    return 0;
}