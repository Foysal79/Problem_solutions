#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int row = n, col = n;
    int a[row][col];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == j)
            {
                primaryDiagonalSum += a[i][j];
            }
            if(i+j == n-1){
                secondaryDiagonalSum += a[i][j];
            }
        }
    }

    cout << abs(primaryDiagonalSum - secondaryDiagonalSum) << endl;


    return 0;
}