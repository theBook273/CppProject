#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int m[1000000];

signed main() {
    cin.tie()->sync_with_stdio(false);
    int n, temp, cnt = 0;
    cin >> n;

    while (cin >> temp) {
        m[temp]++;
        if (m[temp] > 1) {
            cout << "NO";
            return 0;
        }
        cnt++;
        if (cnt > n) {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (m[i] == 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
