#include <bits/stdc++.h>
using namespace std;

void capitalToSmall(string &str)
{

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}

int main()
{

    string str1, str2;
    cin >> str1 >> str2;

    capitalToSmall(str1);
    capitalToSmall(str2);

    if (str1 < str2)
    {
        cout << "-1" << endl;
    }
    else if (str1 > str2)
    {
        cout << "1" << endl;
    }
    else if (str1 == str2)
    {
        cout << "0" << endl;
    }

    return 0;
}