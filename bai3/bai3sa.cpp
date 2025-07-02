#include <bits/stdc++.h>
using namespace std;

long long main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;
    vector<pair<long long, long long>> boxes(N);
    for (auto& box : boxes) {
        long long a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        box = {a, b};
    }

    sort(boxes.begin(), boxes.end());

    vector<long long> lis;

    for (const auto& box : boxes) {
        long long h = box.second;
        auto it = lower_bound(lis.begin(), lis.end(), h);
        if (it == lis.end()) {
            lis.push_back(h);
        } else {
            *it = h;
        }
    }

    cout << lis.size() << "\n";
    return 0;
}
