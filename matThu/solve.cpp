#include <bits/stdc++.h>

using namespace std;

long long n, k;

long long hoa(long long x) {
    x += k;
    x %= 26;
    while (x < 'A') x += 26;
    return x;
}

long long thuong(long long x) {
    x -= k;
    while (x < 'a') {
        x += 26;
    }
    return x;
}

long long main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    k %= 26;
    char s[n];

    for (auto &i : s) cin >> i;

    for (long long i = 0; i < n; ++i) {
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = hoa(s[i]);
        else
            s[i] = thuong(s[i]);
    }

    for (auto i : s) cout << i;
}
