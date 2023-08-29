#include <bits/stdc++.h>

using namespace std;
int a[100];
int n, m, res = 0;
vector<int> v;

bool check[100];

void solve(int tong, int a[], int pos) {
    if (tong == m) {
        res++;
        return;
    }

    for (int i = pos; i < n; i++) {
        if (tong + a[i] <= m) {
            tong += a[i];
            check[i] = 1;
            v.push_back(a[i]);

            solve(tong, a, pos + 1);
            check[i] = 0;
            tong -= a[i];
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    solve(0, a, 0);

    cout << res;
}