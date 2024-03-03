#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;

bool so(string s) {
    while (s.size() > 1) {
        ll tong = 0;

        for (ll i = 0; i < s.size(); i++) {
            double temp = pow(s[i] - '0', 2);
            tong += temp;
        }

        s = to_string(tong);
    }
    // cout << s << endl;
    return s == "1";
}

signed main() {
    cin >> s;
    so(s);
    // s = to_string(stoi(s) + 1);
    // while (!so(s)) {
    //     s = to_string(stoi(s) + 1);
    // }
    // cout << s << endl;
}
