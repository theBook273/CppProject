#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e5 + 27;

vector<pair<char, long long>> dem1, dem2;

long long main() {
    long long t;
    cin >> t;
    while (t--) {
        dem1.clear();
        dem2.clear();
        string a, b;
        cin >> a >> b;
        for (long long i = 0; i < a.size(); i++) {
            long long dem = 1;
            char temp = a[i];
            while (a[i] == a[i + 1]) i++, dem++;
            dem1.push_back({temp, dem});
        }
        for (long long i = 0; i < b.size(); i++) {
            long long dem = 1;
            char temp = b[i];
            while (b[i] == b[i + 1]) i++, dem++;
            dem2.push_back({temp, dem});
        }

        bool check = 0;

        if (dem1.size() == dem2.size()) {
            check = 1;
            for (long long i = 0; i < dem1.size(); ++i) {
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
