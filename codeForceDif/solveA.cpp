#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long q;
    cin >> q;

    while (q--) {
        string s, eg = "codeforces";
        cin >> s;

        long long tong = 0;

        for (long long i = 0; i < s.size(); i++) {
            if (s[i] != eg[i]) {
                tong++;
            }
        }
        cout << tong << endl;
    }
}
