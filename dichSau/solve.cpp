#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    char a[n];

    int b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    for (int i = 0; i < n; i++) {
        if ('a' <= a[i] && a[i] <= 'z') {
            a[i] = toupper(a[i]);
        } else {
            b[i] += m;
            while (b[i] > 'Z') {
                b[i] = b[i] - ('Z' - 'A' + 1) * (b[i] / 'Z');
            }
            a[i] = b[i];
        }
    }

    for (auto i : a) {
        cout << i;
    }
}