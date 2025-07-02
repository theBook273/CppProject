#include <bits/stdc++.h>

using namespace std;

long long n;
string s, res;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;

    for (long long i = 0; i < s.size(); i++) {
        if (res.size() % 2 == 0 || res.back() != s[i]) {
            res += s[i];
        }
    }
    if (res.size() % 2) res.pop_back();
    cout << (n - res.size()) << "\n" << res << "\n";
}
