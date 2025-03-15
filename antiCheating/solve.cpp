#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tong = 0;
    queue<pair<int, int>> p;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
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