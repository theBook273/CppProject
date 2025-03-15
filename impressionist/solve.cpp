#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, cnt[400009], sum[400009], l[400009], r[400009];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        int temp = 0;

        for (int i = 1; i <= 2 * n; ++i) sum[i] = cnt[i] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
            temp = max(max(l[i], r[i]), temp);
            if (l[i] == r[i]) {
                sum[l[i]] = 1;
                cnt[l[i]]++;
            }
        }

        for (int i = 2; i <= temp; i++) {
            sum[i] += sum[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            if ((l[i] == r[i] && cnt[l[i]] <= 1) ||
                (l[i] != r[i] && sum[r[i]] - sum[l[i] - 1] < r[i] - l[i] + 1))
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}