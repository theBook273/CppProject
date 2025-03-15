#include <bits/stdc++.h>

using namespace std;

const int maxn = 5 * 1e5 + 9;

int n, a[maxn];
int cou[maxn + 90];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;

    for (int i(0); i < n; ++i) {
        cin >> a[i];
    }

    vector<int> uc;

    for (int i(1); i <= sqrt(n); ++i) {
        if (n % i == 0) {
            uc.push_back(i);
            if (n / i != i) {
                uc.push_back(n / i);
            }
        }
    }

    sort(uc.begin(), uc.end());

    unordered_map<int, int> vl;
    vector<int> compress;

    for (int i = 0; i < n; i++) {
        if (!vl.count(a[i])) {
            vl[a[i]] = vl.size();
        }
        compress.push_back(vl[a[i]]);
    }

    cout << uc.size() << "\n";

    int current = 1;

    for (auto i : uc) {
        int l(0), res(1e9);
        int unique = 0;

        for (int r = 0; r < n; r++) {
            if (cou[compress[r]] != current) {
                cou[compress[r]] = current;
                unique++;
            }
            if (r - l + 1 == i) {
                res = min(res, unique);
                unique = 0;
                current++;
                l = r + 1;
            }
        }

        cout << i << " " << res << "\n";
    }
}