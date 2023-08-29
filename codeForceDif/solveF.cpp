#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;

    cin >> q;

    while (q--) {
        int n, m;

        cin >> n >> m;

        vector<long long> v[n];

        for (int i = 0; i < m; i++) {
            int temp1, temp2;

            cin >> temp1 >> temp2;

            v[temp1 - 1].push_back(temp2 - 1);
            v[temp2 - 1].push_back(temp1 - 1);
        }

        int dem = 0;

        for (auto i : v) {
            if (i.size() <= 1) {
                continue;
            }

            int temp = v[i[0]].size() - 1;

            if (temp == 0) continue;

            for (int j = 0; j < i.size(); j++) {
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