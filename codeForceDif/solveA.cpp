#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        string s, eg = "codeforces";
        cin >> s;

        int tong = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != eg[i]) {
                tong++;
            }
        }
        cout << tong << endl;
    }
}