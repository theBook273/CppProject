#include <bits/stdc++.h>
#define int long long

using namespace std;

int dsu[100009], sizeA[100009], c, res;

int parent(int x) {
    if (dsu[x] == x) return x;
    dsu[x] = parent(dsu[x]);
    return dsu[x];
}

void join(int a, int b) {
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
    int n, m;
    cin >> n >> m;
    
    c = n;

    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        sizeA[i] = 1;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        join(a, b);
        
        cout << c << " " << res << endl;
    }
}