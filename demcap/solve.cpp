#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 5 * 1e5 + 8;

int a[maxn];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}