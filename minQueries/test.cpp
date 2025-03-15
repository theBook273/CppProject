#include <bits/stdc++.h>

using namespace std;

int a[1000], st[1000][1000];
int n;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        st[0][i] = a[i];
    }

    for (int i = 1; i * 2 < n; i++) {
        for (int j = 0; j + 1 < n; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + 1]);
        }
    }

    for (int i = 0; i * 2 < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << st[i][j] << " ";
        }
        cout << "\n";
    }
}
