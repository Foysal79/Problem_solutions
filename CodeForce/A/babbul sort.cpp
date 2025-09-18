#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    bubbleSort(ar, n);

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}