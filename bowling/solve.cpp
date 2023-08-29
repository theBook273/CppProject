#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;

        cin >> a;

        int dem = 1;

        while (a - dem >= 0) {
            a -= dem;
            dem++;
        }

        cout << ((a == 0) ? "YES \n" : "NO \n");
    }
}