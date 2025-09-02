#include <bits/stdc++.h>
using namespace std;
void shorting(int a[], int n)
{
      for(int i = 0; i < n -1; i++)
      {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
      }
}
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    shorting(a, n);
    shorting(b, n);

    bool ans = true;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i]){
            ans = false;
            cout << "no" << endl;
            return 0;
        }
    }
    if(ans) cout << "yes" << endl;
    

    return 0;

}