#include <bits/stdc++.h>
using namespace std;
int main()
{

    int row, col;
    cin >> row >> col;
    int a[row][col];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    // for(int i = 0; i < row; i++)
    // {
    //     for(int j = 0; j < col; j++)
    //     {
    //         cout << a[i][col-j-1] << " ";
    //     }
    //     cout << endl;
    // }

    //* use tow pointer
    
    for(int i = 0; i < row; i++)
    {
        int x = 0, y = col - 1;
        while(x < y)
        {
           swap(a[i][x], a[i][y]);
            x++;
            y--;
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
