#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long q;

    cin >> q;

    while (q--) {
        long long n, m;

        cin >> n >> m;

        vector<long long> v[n];

        for (long long i = 0; i < m; i++) {
            long long temp1, temp2;

            cin >> temp1 >> temp2;

            v[temp1 - 1].push_back(temp2 - 1);
            v[temp2 - 1].push_back(temp1 - 1);
        }

        long long dem = 0;

        for (auto i : v) {
            if (i.size() <= 1) {
                continue;
            }

            long long temp = v[i[0]].size() - 1;

            if (temp == 0) continue;

            for (long long j = 0; j < i.size(); j++) {
                if (v[i[j]].size() - 1 != temp) {
                    temp = v[i[j]].size() - 1;
                }
            }

            if (temp == v[i[0]].size() - 1) {
                cout << i.size() << " " << v[i[0]].size() - 1 << endl;
            }

            // cout << dem << " ";

            // for (auto j : i) {
            //     cout << j << " ";
            // }
            // cout << endl;

            // dem++;
        }
    }
}
