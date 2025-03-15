#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b, c, tich = 1;

string solve() {
    a *= b;
    // cout << a << endl;
    if (a % 2 == 0 && c % 2 != 0) {
        return "NO";
    }
    while (to_string(a).size() < to_string(c).size()) {
        tich++;
        a *= b;
        // cout << a << endl;
    }
    while (1 == 1) {
        if (to_string(a).size() >= to_string(c).size()) {
            if (to_string(a).substr(to_string(a).size() -
                                    to_string(c).size()) == to_string(c))
                break;
        }
        tich++;
        a *= b;
        if (to_string(a).size() >= to_string(c).size())
            a = stoll(
                to_string(a).substr(to_string(a).size() - to_string(c).size()));
        cout << a << endl;
    }
    return to_string(tich);
}

signed main() {
    cin >> a >> b >> c;
    cout << solve();
}