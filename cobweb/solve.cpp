#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v[10000];

void pieceSearch(int n) {
    for (int i = 0; i < v[n].size(); i++) {
        pieceSearch(v[n][i].first);
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;

        cin >> a >> b;

        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }

    int q;

    cin >> q;

    while (q--) {
        int tear;

        cin >> tear;

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j].second == tear) {
                    v[i][j].second = 0;
                    v[i][j].first = 0;
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < v[i].size(); j++) {
                if (v[i][j].second != 0) {
                    pieceSearch(v[i][j].second);
                }
            }
        }

        // for (int i = 1; i <= m; i++) {
        //     cout << "(" << i << ") ";
        //     for (auto j : v[i]) {
        //         cout << j.first << " " << j.second << "|";
        //     }
        //     cout << endl;
        // }
        // cout << endl << endl;
    }
}