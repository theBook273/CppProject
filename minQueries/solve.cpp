#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    int a[n], tong = m;

    vector<int> maxV;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        maxV.push_back(max(a[i], a[i + 1]));
    }

    // for (auto i : maxV) {
    //     cout << i << " ";
    // }

    for (int j = 0; j < m; j++) {
        int l, r, mi = -1e9;

        cin >> l >> r;

        if (l > r) {
            swap(l, r);
        }

        for (int i = l - 1; i < r - 1; i += 2) {
            mi = max(maxV[i], mi);
        }

        if (mi > a[l - 1]) {
            tong--;
        }
    }
    cout << tong << endl;
}