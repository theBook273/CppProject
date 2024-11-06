#include <bits/stdc++.h>
#define int long long

using namespace std;

int tree[100009];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = n; i <= n * 2 - 1; i++) {
        tree[i] = 1;
    }
}