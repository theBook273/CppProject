#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        pair<long long, long long> a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        int res[n];

        for (int i = 0; i < n; i++) {
            res[i] = 1;
        }

        sort(a, a + n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i].second >= a[j].second) {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }

        cout << *max_element(res, res + n) << endl;
    }
}
