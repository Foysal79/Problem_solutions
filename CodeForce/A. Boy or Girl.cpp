#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin >> s;

    int freq[26] = {0};
    int dis = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        if(freq[index] == 0)
        {
            freq[index] = 1;
            dis++;
        }
    }
    if(dis%2 == 0){
        cout <<"CHAT WITH HER!" << endl;
    } 
    else {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}