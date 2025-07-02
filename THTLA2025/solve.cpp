#include <bits/stdc++.h>

using namespace std;

signed main() {
    long long n;
    cin >> n;

    unordered_map<string, long long> mp;

    for (long long i = 0; i < 2 * n - 1; i++) {
        string temp;
        cin >> temp;
        mp[temp]++;
    }
    for (auto [i, j] : mp) {
        if (j & 1) cout << i;
    }
}
