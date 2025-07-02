#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long lazy[100000], tree[100000];
long long n, m;

void update(long long b, long long e, long long l, long long r, long long node) {
    long long left = node * 2;
    long long right = node * 2 + 1;
    long long mid = (b + e) / 2;

    if (lazy[node] == 1) {
        tree[node] = (e - b + 1) - tree[node];
        if (b != e) {
            lazy[left] = 1 - lazy[left];
            lazy[right] = 1 - lazy[right];
        }
        lazy[node] = 0;
    }

    if (b > r || e < l) return;

    if (b >= l && e <= r) {
        tree[node] = (e - b + 1) - tree[node];
        if (b != e) {
            lazy[left] = 1 - lazy[left];
            lazy[right] = 1 - lazy[right];
        }
        return;
    }

    update(b, mid, l, r, left);
    update(mid + 1, e, l, r, right);

    tree[node] = tree[left] + tree[right];

    return;
}

long long query(long long b, long long e, long long l, long long r, long long node) {
    if (b > r || e < l) return 0;

    long long left = node * 2;
    long long right = node * 2 + 1;
    long long mid = (b + e) / 2;

    if (lazy[node] == 1) {
        tree[node] = (e - b + 1) - tree[node];
        if (b != e) {
            lazy[left] = 1 - lazy[left];
            lazy[right] = 1 - lazy[right];
        }
        lazy[node] = 0;
    }
    if (l <= b && e <= r) return tree[node];

    long long x = query(b, mid, l, r, left);
    long long y = query(mid + 1, e, l, r, right);

    return x + y;
}
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    while (m--) {
        long long x, l, r;
        cin >> x >> l >> r;

        if (x == 0) update(l, r, 1, n, 1);
        if (x == 1) cout << query(l, r, 1, n, 1) << endl;
    }
}
