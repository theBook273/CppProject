#include <bits/stdc++.h>

using namespace std;
long long n, m, res = 0;
vector<pair<long long, long long>> v;

bool check[100];

// void solve(long long tong, long long a[], long long pos) {
//     if (tong == m) {
//         res++;

//         // for (auto i : v) {
//         //     cout << i.first << " ";
//         // }
//         // cout << endl;
//         return;
//     }

//     long long temp = 0;

//     if (!v.empty()) {
//         temp = v.back().second + 1;
//     }

//     for (long long i = temp; i < n; i++) {
//         if (tong + a[i] <= m) {
//             tong += a[i];
//             v.push_back({a[i], i});

//             solve(tong, a, pos + 1);
//             tong -= a[i];
//             v.pop_back();
//         }
//     }
// }

void binarySearch() {}

long long main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        v.push_back({temp, i});
    }

    sort(v.begin(), v.end());

    cout << res;
}
