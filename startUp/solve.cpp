#include <bits/stdc++.h>
#define long long long long

using namespace std;

bool comp(pair<long long, long long> a, pair<long long, long long> b) { return a.second > b.second; }

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    long long t;
    cin >> t;

    while (t--) {
        long long n, k;

        cin >> n >> k;

        n--;

        map<long long, long long> mp;

        for (long long i = 0; i < k; i++) {
            long long a, b;
            cin >> a >> b;

            mp[a] += b;
        }

        vector<pair<long long, long long>> p;

        for (auto i : mp) {
            p.push_back({i.first, i.second});
        }

        sort(p.begin(), p.end(), comp);

        long long tong = 0;

        for (long long i = 0; i < p.size(); i++) {
            if (i > n) break;

            tong += p[i].second;
        }

        cout << tong << endl;
    }
}
