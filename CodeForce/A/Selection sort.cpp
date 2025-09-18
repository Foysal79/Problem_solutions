#include <bits/stdc++.h>
using namespace std;
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_Index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_Index])
            {
                min_Index = j;
            }
        }
        swap(a[i], a[min_Index]);
    }
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}