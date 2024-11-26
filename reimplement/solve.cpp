#include <bits/stdc++.h>
#define int long long

using namespace std;

int node[1000000], lazy[1000000];
int n, m;

void update(int l, int r, int u, int v, int id) {
    if (lazy[id] == 1) {
        node[id] = (r - l + 1) - node[id];

        if (l != r) {
            lazy[id * 2] = 1 - lazy[id * 2];
            lazy[id * 2 + 1] = 1 - lazy[id * 2 + 1];
        }
        lazy[id] = 0;
    }

    if (l < u || v < r) {
        return;
    }

    if (u <= l && r <= v) {
        node[id] = (r - l + 1) - node[id];
        if (l != r) {
            lazy[id * 2] = 1 - lazy[id * 2];
            lazy[id * 2 + 1] = 1 - lazy[id * 2 + 1];
        }
        return;
    }

    int mid = (l + r) / 2;
    update(l, mid, u, v, id * 2);
    update(mid + 1, r, u, v, id * 2 + 1);
    node[id] = node[id * 2] + node[id * 2 + 1];
}

int queries(int l, int r, int u, int v, int id) {
    if (l < u || v < r) {
        return 0;
    }

    if (lazy[id] == 1) {
        node[id] = (r - l + 1) - node[id];
        if (l != r) {
            lazy[id * 2] = 1 - lazy[id * 2];
            lazy[id * 2 + 1] = 1 - lazy[id * 2 + 1];
        }
        lazy[id] = 0;
    }

    if (u <= l && r <= v) {
        return node[id];
    }

    int mid = (l + r) / 2;
    return queries(l, mid, u, v, id * 2) +
           queries(mid + 1, r, u, v, id * 2 + 1);
}

signed main() {
    // freopen("flipcoin.inp", "r", stdin);
    // freopen("flipcoin.out", "w", stdout);
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;

    while (m--) {
        int l, r, u;
        cin >> u >> l >> r;
        if (u == 1) {
            cout << queries(l, r, 1, n, 1) << endl;
        } else {
            update(l, r, 1, n, 1);
        }
    }
}