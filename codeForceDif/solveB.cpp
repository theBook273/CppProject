#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        int tong = 0, maxN = 0, a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] == 0) {
                tong++;
                maxN = max(maxN, tong);
            }
            if (a[i] == 1) {
                tong = 0;
            }
        }
        cout << maxN;
    }
}