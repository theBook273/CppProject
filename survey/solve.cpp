#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<char, int> dem;
        for (auto i : s) {
            dem[i]++;
        }
        if (dem['Y'] > dem['N']) {
            cout << "APPROVED \n";
        } else if (dem['Y'] < dem['N']) {
            cout << "REJECTED \n";
        } else {
            cout << "UNCERTAIN \n";
        }
    }
}