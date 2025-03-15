#include <bits/stdc++.h>

using namespace std;

long long a[1000000], st[1000000], n, q;

void buildTree(long long id, long long l, long long r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    long long m = (l + r) / 2;

    buildTree(id * 2, l, m);
    buildTree(id * 2 + 1, m + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

void replaceTree(long long id, long long l, long long r, long long i,
                 long long v, bool deleted) {
    if (i < l || i > r) {
        return;
    }

    if (r == l) {
        if (deleted) {
            cout << st[id] << endl;
            st[id] = v;
        } else
            st[id] += v;
        return;
    }

    long long m = (l + r) / 2;

    replaceTree(id * 2, l, m, i, v, deleted);
    replaceTree(id * 2 + 1, m + 1, r, i, v, deleted);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

long long getSum(long long id, long long l, long long r, long long u,
                 long long v) {
    if (r < u || v < l) {
        return 0;
    }

    if (u <= l && r <= v) {
        return st[id];
    }

    long long m = (l + r) / 2;

    long long left = getSum(id * 2, l, m, u, v);
    long long right = getSum(id * 2 + 1, m + 1, r, u, v);

    return left + right;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    long long loop;

    cin >> loop;

    for (int dem = 1; dem <= loop; dem++) {
        cout << "Case " << dem << ": " << endl;
        cin >> n >> q;

        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }

        buildTree(1, 1, n);

        // for (long long i = 0; i <= n * 10; i++) {
        //     cout << st[i] << " ";
        // }
        // replaceTree(1, 1, n, 2, 3, 0);
        // cout << getSum(1, 1, n, 1 + 1, 3 + 1) << endl;

        while (q--) {
            long long type;

            cin >> type;

            if (type == 1) {
                long long temp;

                cin >> temp;

                temp++;

                replaceTree(1, 1, n, temp, 0, 1);
            }

            else if (type == 2) {
                long long i, v;

                cin >> i >> v;

                i++;

                replaceTree(1, 1, n, i, v, 0);
            } else {
                long long i, j;

                cin >> i >> j;

                i++, j++;

                cout << getSum(1, 1, n, i, j) << endl;
            }
        }
    }
}