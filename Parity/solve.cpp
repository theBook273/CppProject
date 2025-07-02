#include <bits/stdc++.h>

using namespace std;

map<long long, long long> p;

long long search(long long x) {
    if (p[x] == x) return x;
    return p[x] = search(p[x]);
}

void makeU(long long x, long long y) {
    x = search(x);
    y = search(y);

    if (x != y) {
        p[x] = y;
    }
}

long long main() {
    long long n, q;
    cin >> n;

    while (n != -1) {
        const long long neg = n + 6;

        cin >> q;

        p.clear();

        bool flg = 0;

        for (long long i = 1; i <= q; i++) {
            long long r, l;
            string st;

            cin >> l >> r >> st;

            if (!flg) {
                l--;

                if (!p.count(l)) {
                    p[l] = l;
                    p[l + neg] = l + neg;
                }
                if (!p.count(r)) {
                    p[r] = r;
                    p[r + neg] = r + neg;
                }

                if (st == "even") {
                    makeU(l, r);
                    makeU(l + neg, r + neg);
                } else if (st == "odd") {
                    makeU(l, r + neg);
                    makeU(l + neg, r);
                }

                if (search(l) == search(l + neg) ||
                    search(r) == search(r + neg) || l < 0 || r > n) {
                    cout << i - 1 << "\n";
                    flg = 1;
                }
            }
        }

        cin >> n;
    }
}
