#include <bits/stdc++.h>

using namespace std;

bool checkPal(string s) {
    stack<char> ca;
    bool odd = (s.size()) % 2;

    for (int i = 0; i < s.size(); i++) {
        if (odd && i == (s.size() / 2)) continue;
        if (!ca.empty()) {
            if (ca.top() == s[i]) ca.pop();
        } else
            ca.push(s[i]);
    }
    return ca.empty();
}

signed main() {
    string sam;
    cin >> sam;

    if (checkPal(sam))
        cout << sam;
    else {
        string a = sam;
        reverse(sam.begin(), sam.end());
        cout << a;
        for (int i = 1; i < sam.size(); i++) {
            cout << sam[i];
        }
    }
}