#include <bits/stdc++.h>
using namespace std;

int a[1000009], pre[1000009], maxN[1000009], minN[1000009];
int l, r;
int n, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    pre[1] = a[1];

    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    minN[0] = 1e9;
    for (int i = 1; i <= n; i++) minN[i] = min(minN[i - 1], pre[i]);

    maxN[n + 1] = -1e9;
    for (int i = n; i >= 0; i--) maxN[i] = max(maxN[i + 1], pre[i]);

    minN[0] = 0;

    while (t--) {
        cin >> l >> r;

        cout << maxN[r] - minN[l - 1] << "\n";
    }
}
