#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    long long a[n], tong = m;

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < m; i++) {
        long long temp1, temp2;

        cin >> temp1 >> temp2;

        if (temp1 > temp2) {
            swap(temp1, temp2);
        }

        for (long long j = temp1; j < temp2; j++) {
            if (a[j] > a[temp1]) {
                tong--;
                break;
            }
        }

        cout << tong;
    }
}