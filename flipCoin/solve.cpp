#include <bits/stdc++.h>

using namespace std;
#define mx 100005
#define ll long long
#define forn(i, n) for (long long i = 0; i < (long long)n; i++)
#define mem(a) memset(a, 0, sizeof(a))
// long long arr[mx];
long long tree[mx * 3];
long long lazy[mx * 3];
// long long carry;

long long query(long long node, long long b, long long e, long long i, long long j) {
    // cout<<"query= "<<carry<<endl;
    if (b > j || e < i) return 0;

    long long Left = node * 2;
    long long Right = node * 2 + 1;
    long long mid = (b + e) / 2;

    if (lazy[node] == 1) {
        tree[node] = (e - b + 1) - tree[node];  // updating tree

        if (b != e) {
            lazy[Left] = 1 - lazy[Left];

            lazy[Right] = 1 - lazy[Right];
        }

        lazy[node] = 0;
    }

    if (b >= i && e <= j) return tree[node];
    long long x = query(Left, b, mid, i, j);
    long long y = query(Right, mid + 1, e, i, j);
    return x + y;
}

void update(long long node, long long b, long long e, long long i, long long j) {
    long long Left = node * 2;
    long long Right = node * 2 + 1;
    long long mid = (b + e) / 2;

    if (lazy[node] == 1) {
        tree[node] = (e - b + 1) - tree[node];

        if (b != e) {
            lazy[Left] = 1 - lazy[Left];
            lazy[Right] = 1 - lazy[Right];
        }
        lazy[node] = 0;
    }

    if (b > j || e < i) return;

    if (b >= i && e <= j) {
        tree[node] = (e - b + 1) - tree[node];
        // cout<<"node = "<<node<<" "<<tree[node]<<endl;
        if (b != e) {
            lazy[Left] = 1 - lazy[Left];
            lazy[Right] = 1 - lazy[Right];
        }
        return;
    }

    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);

    tree[node] = tree[Left] + tree[Right];
}

long long main() {
    // ios::sync_with_stdio(false);
    long long n, m;
    scanf("%d%d", &n, &m);

    while (m--) {
        long long t;
        scanf("%d", &t);

        if (t == 1) {
            long long i, j;
            scanf("%d%d", &i, &j);
            i++, j++;
            long long d = query(1, 1, n, i, j);

            prlong longf("%d\n", d);
        }

        else {
            long long i, j;
            scanf("%d%d", &i, &j);
            i++, j++;
            update(1, 1, n, i, j);
        }
    }

    return 0;
}
