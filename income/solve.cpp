#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll st[100000], a[100000];

void initTree(ll l, int r, int id) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    ll m = (l + r) / 2;

    initTree(l, m, id * 2);
    initTree(m + 1, r, id * 2 + 1);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void replaceTree(ll l, int r, int id, int x, int i) {
    if (l < x || r > x) {
        return;
    }
    if (l == r) {
        st[id] = i;
    }

    ll m = (l + r) / 2;
    replaceTree(l, m, id * 2, x, i);
    replaceTree(m + 1, r, id * 2 + 1, x, i);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll maxNode(int l, int r, int u, int v, int id) {
    if (l > v || r < u) {
        return -1e9;
    }
    if (l >= u && v >= r) {
        return st[id];
    }

    ll m = (l + r) / 2;
    ll maxL = maxNode(l, m, u, v, id * 2);
    ll maxR = maxNode(m + 1, r, u, v, id * 2 + 1);

    return max(maxL, maxR);
}

ll main() {
    ll n, year = 0;

    cin >> n;

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    initTree(1, n, 1);

    // cout << maxNode(1, n, 1, n, 1) << endl;

    for (ll i = 1; i <= n; i++) {
        ll l, r;

        cin >> l >> r;

        ll temp = maxNode(1, n, l, r, 1);

        // cout << temp << endl;
        if (temp > a[i]) {
            replaceTree(1, n, 1, i, temp);
            a[i] = temp;
            year = i;
        }
        // for (ll i = 1; i <= n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
    }

    cout << year;
}
/*
    1 2 3 4

    2 2 3 4
    2 3 3 4
    2 3 3 4
    2 3 3 4
*/
