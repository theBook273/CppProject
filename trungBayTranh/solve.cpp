#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[500009];
int n;
int prefix[500009];

int check(int i, int j) {
    if (a[j].first - a[i].first <= prefix[j] - prefix[i - 1]) return 1;
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    prefix[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1].second;
    }

    int res = 0;

    for (int l = 0; l < n; l++) {
        int r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(l, mid)) {
                res = max(res, prefix[mid] - prefix[l - 1] -
                                   (a[mid].first - a[l].first));
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    cout << res << endl;
}