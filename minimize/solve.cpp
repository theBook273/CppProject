#include <bits/stdc++.h>

using namespace std;

signed main() {
    long long n;
    cin >> n;
    char s[n];

    for (auto &i : s) cin >> i;

    bool check = 0;

    for (long long i = 0; i < n; ++i) {
        if (!check && s[i] > s[i + 1]) {
            check = 1;
            continue;
        }
        cout << s[i];
    }
}
