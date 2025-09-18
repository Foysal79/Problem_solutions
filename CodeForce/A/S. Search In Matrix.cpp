#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    int m[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            cin >> m[i][j];
        }
    }
    int x, f = 0;
    cin >> x;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (m[i][j] == x)
            {
                f = 1;
                break;
            }
        }
    }
    if (f == 0)
    {
        cout << "will take number" << endl;
    }
    else {
        cout << "will not take number" << endl;
    }

    return 0;
}