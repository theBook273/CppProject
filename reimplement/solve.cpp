#include <bits/stdc++.h>
#define int long long

using namespace std;

int lazy[100000], tree[100000];
int n, m;

void update(int b, int e, int l, int r, int node) {
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

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

int query(int b, int e, int l, int r, int node) {
    if (b > r || e < l) return 0;

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    if (lazy[node] == 1) {
        tree[node] = (e - b + 1) - tree[node];
        if (b != e) {
            lazy[left] = 1 - lazy[left];
            lazy[right] = 1 - lazy[right];
        }
        lazy[node] = 0;
    }
    if (l <= b && e <= r) return tree[node];

    int x = query(b, mid, l, r, left);
    int y = query(mid + 1, e, l, r, right);

    return x + y;
}
signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> m;

    while (m--) {
        int x, l, r;
        cin >> x >> l >> r;

        if (x == 0) update(l, r, 1, n, 1);
        if (x == 1) cout << query(l, r, 1, n, 1) << endl;
    }
}