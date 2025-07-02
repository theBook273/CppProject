#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long tree[100009];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long n;
    cin >> n;

    for (long long i = n; i <= n * 2 - 1; i++) {
        tree[i] = 1;
    }
}
