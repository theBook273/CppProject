#include <bits/stdc++.h>
#define int long long

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, k;

        cin >> n >> k;

        n--;

        map<int, int> mp;

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            mp[a] += b;
        }

        vector<pair<int, int>> p;

        for (auto i : mp) {
            p.push_back({i.first, i.second});
        }

        sort(p.begin(), p.end(), comp);

        int tong = 0;

        for (int i = 0; i < p.size(); i++) {
            if (i > n) break;

            tong += p[i].second;
        }

        cout << tong << endl;
    }
}