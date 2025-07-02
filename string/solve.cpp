#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    string tag;

    while (cin >> tag) {
        if (tag == "[END]") break;
        string s, t;
        cin >> s >> t;

        long long num[100000];

        for (long long i = 0; i < s.size(); i++) {
            long long m = min(s[i], t[i]), l = max(s[i], t[i]);
            num[i] = l - m;
        }

        string res;

        for (long long i = 0; i < s.size(); i++) {
            char m = min(s[i], t[i]);
            if (num[i] < 13)
                res.push_back(m);
            else
                res.push_back('a');
        }

        cout << res << endl;
    }
}
