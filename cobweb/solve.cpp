#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> v[10000];

void pieceSearch(long long n) {
    for (long long i = 0; i < v[n].size(); i++) {
        pieceSearch(v[n][i].first);
    }
}

long long main() {
    long long n, m;

    cin >> n >> m;

    for (long long i = 1; i <= m; i++) {
        long long a, b;

        cin >> a >> b;

        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }

    long long q;

    cin >> q;

    while (q--) {
        long long tear;

        cin >> tear;

        for (long long i = 1; i <= m; i++) {
            for (long long j = 0; j < v[i].size(); j++) {
                if (v[i][j].second == tear) {
                    v[i][j].second = 0;
                    v[i][j].first = 0;
                }
            }
        }

        for (long long i = 1; i <= m; i++) {
            for (long long j = 1; j < v[i].size(); j++) {
                if (v[i][j].second != 0) {
                    pieceSearch(v[i][j].second);
                }
            }
        }

        // for (long long i = 1; i <= m; i++) {
        //     cout << "(" << i << ") ";
        //     for (auto j : v[i]) {
        //         cout << j.first << " " << j.second << "|";
        //     }
        //     cout << endl;
        // }
        // cout << endl << endl;
    }
}
