#include <bits/stdc++.h>

using namespace std;

bool breakGold(int n, int m) {
    if (n == m) {
        return 1;
    }

    if (n % 3 == 0) {
        return breakGold(n / 3, m) == 1 ? breakGold(n / 3, m)
                                        : breakGold(n - n / 3, m);
    }

    return 0;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m;
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