#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    long long n, k;
    string s, temp;
    cin >> n >> s >> k;
    temp = s;

    while (k >= 26) {
        k -= 26;
    }

    for (auto &i : s) {
        if (isalpha(i)) {
            i = tolower(i);
            i += k;
            while (!isalpha(i)) {
                i -= 26;
            }
        }
    }

    for (ll i = 0; i < s.size(); i++) {
        if (isalpha(temp[i]) && temp[i] == toupper(temp[i])) {
            s[i] = toupper(s[i]);
        }
    }
    cout << s;
}
