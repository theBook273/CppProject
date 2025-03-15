#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    ll a;
    string s;

    cin >> n >> a >> s;

    n = s.size();

    if (a == 0) {
        cout << s << a;
    } else if (s[0] - '0' < a) {
        cout << a << s;
    } else {
        string res1, res2;
        bool check = 0;
        ll i;
        for (i = 0; i < n; i++) {
            if ((s[i] == '0' || s[i] - '0' < a) && !check) {
                res1 += s[i];
                res1 += (to_string(a));
                res2 += (to_string(a));
                res2 += s[i];
                check = 1;
                continue;
            }
            res1.push_back(s[i]);
            res2.push_back(s[i]);
        }
        if (res1 == s) {
            cout << s << a;
        } else
            cout << res1;
    }
}