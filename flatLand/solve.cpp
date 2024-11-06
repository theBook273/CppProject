#include <bits/stdc++.h>
#define int long long

using namespace std;

int c[100000];

main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    int res = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(c[j] - i) > 0) res = min(res, abs(c[i] - i));
        }
    }

    cout << res;
}