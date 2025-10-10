#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; 
    cin >> T;

    vector<int> special = {0, 11*60 + 11, 22*60 + 22}; 
    
    while (T--) {
        string time;
        cin >> time;
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));
        int cur = hh * 60 + mm;

        int nextTime = special[0]; 
        for (int t : special) {
            if (t >= cur) {
                nextTime = t;
                break;
            }
        }

        int nh = nextTime / 60;
        int nm = nextTime % 60;

        cout << setw(2) << setfill('0') << nh << ":" 
             << setw(2) << setfill('0') << nm << "\n";
    }

    return 0;
}
