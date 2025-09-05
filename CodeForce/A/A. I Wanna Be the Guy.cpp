#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, bool> game;
    int p; cin >> p;
    for(int i = 0; i < p; i++)
    {
      int x;
      cin >> x;
      game[x] = true;
    }
    int q ; cin >> q;
    for(int i = 0; i < q; i++)
    {
      int x;
      cin >> x;
      game[x] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        if(game[i] == false)
        {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }
    cout << "I become the guy." << endl;
    return 0;
    
   

}