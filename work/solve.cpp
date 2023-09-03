#include <bits/stdc++.h>

using namespace std;
int n, m, res = 0;
vector<pair<int, int>> v;

bool check[100];

// void solve(int tong, int a[], int pos) {
//     if (tong == m) {
//         res++;

//         // for (auto i : v) {
//         //     cout << i.first << " ";
//         // }
//         // cout << endl;
//         return;
//     }

//     int temp = 0;

//     if (!v.empty()) {
//         temp = v.back().second + 1;
//     }

//     for (int i = temp; i < n; i++) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back({temp, i});
    }

    sort(v.begin(), v.end());

    cout << res;
}