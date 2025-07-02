#include <bits/stdc++.h>

using namespace std;

// bool compareS(string s1, string s2) {
//     if (s1.size() != s2.size()) return s1 < s2;

//     for (unsigned long long i = 0; i < s1.size(); i++) {
//         if (s1[i] > s2[i]) return 0;
//         if (s1[i] < s2[i]) return 1;
//     }
//     return 0;
// }

unsigned long long tong(string s) {
    unsigned long long tong = 0;

    for (auto i : s) {
        tong += (i - '0');
    }

    return tong;
}

long long main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long t;
    cin >> t;

    while (t--) {
        unsigned long long s;

        cin >> s;

        unsigned long long tong1 = tong(to_string(s));

        if (tong1 == 1 || tong1 == 0) {
            cout << -1 << endl;
            continue;
        }

        if (s < 10) {
            cout << 10 << endl;
        } else {
            unsigned long long res = s;
            unsigned long long dem = 1;
            while (tong(to_string(res)) >= tong1) {
                unsigned long long div = pow(10, dem);
                res /= div;
                res++;
                res *= div;
                dem++;
            }
            cout << res << endl;
        }
    }
}
