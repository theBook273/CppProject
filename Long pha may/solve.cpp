#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> p;
        int gioihan = k;
        while (k--) {
            int nhan, gia;
            cin >> nhan >> gia;
            p.push_back({nhan, gia});
            // for (auto x : p) {
            //     cout << x.first << " " << x.second << "\n";
            // }
        }
        sort(p.begin(), p.end());
        int sum = 0;
        for (int i = 0; i < p.size(); i++) {
            // cout << p[i].first << " " << p[i].second << " \n";
            int kecu = p[i - 1].first;
            if (p[i].first != kecu) n--;
            sum += p[i].second;
            if (n == 0) break;
        }
        cout << sum << " \n";
    }
}