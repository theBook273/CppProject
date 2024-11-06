#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    freopen("mysterious.inp", "r", stdin);
    freopen("mysterious.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i += 2) {
        string x;
        x += s[i];
        x += s[i + 1];
        int temp = stoi(x);
        cout << char('A' - 65 + temp);
    }
}