#include <bits/stdc++.h>

using namespace std;

long long main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, tong = 0;
    queue<pair<long long, long long>> p;

    cin >> n;

    long long a[n];

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = n - 1; i >= 0; i--) {
        if (a[i] != 0) {
            p.push({i, a[i]});
        }

        while (p.front().first - p.front().second > i && !p.empty()) {
            p.pop();
        }

        if (!p.empty() && i >= p.front().first - p.front().second &&
            i != p.front().first) {
            tong++;
        }
    }

    cout << n - tong;
}
