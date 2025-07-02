#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 27;

vector<pair<char, int>> dem1, dem2;

int main() {
    int t;
    cin >> t;
    while (t--) {
        dem1.clear();
        dem2.clear();
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++) {
            int dem = 1;
            char temp = a[i];
            while (a[i] == a[i + 1]) i++, dem++;
            dem1.push_back({temp, dem});
        }
        for (int i = 0; i < b.size(); i++) {
            int dem = 1;
            char temp = b[i];
            while (b[i] == b[i + 1]) i++, dem++;
            dem2.push_back({temp, dem});
        }

        bool check = 0;

        if (dem1.size() == dem2.size()) {
            check = 1;
            for (int i = 0; i < dem1.size(); ++i) {
                if (dem1[i].first == dem2[i].first &&
                    dem1[i].second <= dem2[i].second)
                    continue;
                else
                    check = 0;
            }
        }

        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}