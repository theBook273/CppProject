#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    string s;

    cin >> s;

    for (long long i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }

    long long l = 0, res = 0;
    char resC;

    for (long long r = 0; r < s.size(); r++) {
        if (s[r + 1] != s[l]) {
            if (r - l + 1 > res) {
                resC = s[l];
                res = r - l + 1;
            }
            l = r + 1;
        }
    }
    cout << resC << " " << res << endl;
}
