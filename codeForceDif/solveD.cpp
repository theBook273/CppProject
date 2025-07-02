#include <bits/stdc++.h>

using namespace std;

bool breakGold(long long n, long long m) {
    if (n == m) {
        return 1;
    }

    if (n % 3 == 0) {
        return breakGold(n / 3, m) == 1 ? breakGold(n / 3, m)
                                        : breakGold(n - n / 3, m);
    }

    return 0;
}

long long main() {
    long long q;
    cin >> q;
    while (q--) {
        long long n, m;
        cin >> n >> m;

        if (n < m) {
            cout << "NO" << endl;
            continue;
        }

        string res = "NO";

        if (breakGold(n, m)) {
            res = "YES";
        }

        cout << res << endl;
    }
}
