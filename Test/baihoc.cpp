#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int x;
    cin >> x;

    string s;

    for (int i = 1; i <= 10000; i++) {
        s += to_string(i);
        if (s.size() > x) {
            cout << s[x - 1];
            return 0;
        }
    }
}