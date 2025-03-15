#include <bits/stdc++.h>

using namespace std;

int a[1000000];

int tong = 0;

int dp(int l, int r, int k) {
    int forPiu = 0, toCut, side = 0;

    while (k--) {
        int tong1, tong2;

        tong1 = tong2 = 0;

        for (int i = k - 1; i >= l; i--) {
            cout << a[i] << " ";
            tong1 += a[i];
        }
        cout << endl;

        for (int i = k; i <= r; i++) {
            cout << a[i] << " ";
            tong2 += a[i];
        }
        cout << endl;

        if (forPiu < min(tong1, tong2)) {
            forPiu = min(tong1, tong2);
            toCut = k;
            tong1 == min(tong1, tong2) ? side = l : side = r;
        }
    }

    // cout << forPiu << " " << toCut << " " << side << endl;

    tong += forPiu;

    if (toCut > side) {
        return tong;
    }

    if (side == l)
        return dp(l, toCut, toCut);
    else
        return dp(toCut, r, r);
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dp(0, n - 1, n - 1);
}