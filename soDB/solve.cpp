#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mp[11];
ll preCal[11] = {0,     1,      18,     154,     1106,   6818,
                 35378, 149618, 492338, 1177778, 1863218};
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    ll n, res = 0;
    cin >> n;

    res += preCal[(to_string(n).size()) - 1];

    if (n < 5) {
        cout << 0;
        return 0;
    }

    if (to_string(n).size() >= 10) {
        cout << preCal[10] << endl;
        return 0;
    }

    string temp = "1";
    while (temp.size() < to_string(n).size()) {
        temp += '0';
    }
    // cout << temp << endl;

    for (ll i = stoll(temp); i <= n; i += 5) {
        bool check = 1;
        memset(mp, 0, sizeof(mp));
        for (auto j : to_string(i)) {
            mp[j - '0']++;
            if (mp[j - '0'] > 1) {
                check = 0;
                break;
            }
        }
        if (check) {
            // cout << i << endl;
            res++;
        }
    }
    cout << res;
}
