#include <bits/stdc++.h>
using namespace std;

long long N, k;
vector<long long> x;

bool check(long long D) {
    long long count = 0;
    long long current = 0;
    while (current < N) {
        count++;
        long long target = x[current] + D;
        auto j =
            upper_bound(x.begin() + current, x.end(), target) - x.begin() - 1;
        current = upper_bound(x.begin() + j, x.end(), x[j] + D) - x.begin();
    }
    return count <= k;
}

long long main() {
    // ifstream fin("BUS.INP");
    // ofstream fout("BUS.OUT");
    cin >> N >> k;
    x.resize(N);
    for (long long i = 0; i < N; i++) {
        cin >> x[i];
    }
    long long left = 0, right = x.back() - x[0];
    long long Y = right;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (check(mid)) {
            Y = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << Y << endl;
    return 0;
}
