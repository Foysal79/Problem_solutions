#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1, -1, 1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
bool isValid(int i, int j, int row, int col)
{
    return (i >= 0 && j >= 0 && i < row && j < col);
}
int main()
{

    int row, col;
    cin >> row >> col;
    char matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int xr, yc;
    cin >> xr >> yc;
    xr--;
    yc--;
    bool ans = true;
    for (int i = 0; i < 8; i++)
    {
        int ii = xr + dx[i];
        int jj = yc + dy[i];
        if (isValid(ii, jj, row, col) && matrix[ii][jj] != 'x')
        {
            ans = false;
        }
    }
    if(ans) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}