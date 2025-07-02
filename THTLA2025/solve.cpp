#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    cin >> n;

    unordered_map<string, int> mp;

    for (int i = 0; i < 2 * n - 1; i++) {
        string temp;
        cin >> temp;
        mp[temp]++;
    }
    for (auto [i, j] : mp) {
        if (j & 1) cout << i;
    }
}