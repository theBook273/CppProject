#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        vector<long long> x[n + 3];

        for (long long i = 0; i < m; i++) {
            ll a, b;
            cin >> a >> b;
            x[a].push_back(b);
            x[b].push_back(a);
        }

        for (auto i : x) {
            if (i.size() <= 1) {
                continue;
            }

            ll temp = x[i[0]].size() - 1;

            if (temp == 0) continue;

            for (long long j = 1; j < i.size(); j++) {
                temp = x[i[j]].size() - 1;
            }

            if (temp == x[i[0]].size() - 1) {
                cout << i.size() << " " << x[i[0]].size() - 1 << endl;
            }
        }
    }
}
