#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long x;
    cin >> x;

    string s;

    for (long long i = 1; i <= 10000; i++) {
        s += to_string(i);
        if (s.size() > x) {
            cout << s[x - 1];
            return 0;
        }
    }
}
