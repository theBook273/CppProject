#include <bits/stdc++.h>

using namespace std;

const int maxn = 127;

char a[maxn][maxn];
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        map<int, int> demhang, demcot;
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> a[i][j];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                demhang[i] += (a[i][j] == '1');
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                demcot[j] += (a[i][j] == '1');
            }
        }

        int cnt1, cnt2;
        cnt1 = cnt2 = 0;

        for (auto [i, j] : demhang) {
            cnt1 += (j % 2);
        }
        for (auto [i, j] : demcot) {
            cnt2 += (j % 2);
        }

        cout << max(cnt1, cnt2) << "\n";
    }
}