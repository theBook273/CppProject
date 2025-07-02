#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long dsu[100009], sizeA[100009], c, res;

long long parent(long long x) {
    if (dsu[x] == x) return x;
    dsu[x] = parent(dsu[x]);
    return dsu[x];
}

void join(long long a, long long b) {
    a = parent(a);
    b = parent(b);
    if (a != b) {
        dsu[b] = a;
        sizeA[a] += sizeA[b];
        sizeA[b] = 0;
        res = max(res,sizeA[a]);
        c--;
    }
}

main() {
    cin.tie(0)->sync_with_stdio(0);
    //freopen("test.txt", "w", stdout);
    long long n, m;
    cin >> n >> m;
    
    c = n;

    for (long long i = 1; i <= n; i++) {
        dsu[i] = i;
        sizeA[i] = 1;
    }

    while (m--) {
        long long a, b;
        cin >> a >> b;

        join(a, b);
        
        cout << c << " " << res << endl;
    }
}
