#include <bits/stdc++.h>
using namespace std;

long long b[100000], a[100000], n, t;
vector<long long> sumB, sumA;

signed main() {
    cin.tie()->sync_with_stdio(NULL);
    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    sumA.push_back(0);
    sumB.push_back(0);

    for (long long i = 1; i <= n; i++) {
        sumA.push_back(a[i - 1] + sumA[i - 1]);
        sumB.push_back(b[i - 1] + sumB[i - 1]);
    }

    // for (auto i : sumA) {
    //     cout << i << " ";
    // }

    cin >> t;

    while (t--) {
        long long request, l, r;

        cin >> request >> l >> r;

        if (request == 1) {
            cout << sumA[r] - sumA[l - 1];
        } else if (request == 2) {
            cout << sumB[r] - sumB[l - 1];
        }
        cout << endl;
    }
}
