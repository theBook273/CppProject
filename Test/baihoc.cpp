#include <bits/stdc++.h>

using namespace std;

long long bin(int n, int m) {
    if (m == 0) return 1;
    if (m % 2 == 0) return bin(n, m / 2) * bin(n, m / 2);
    return bin(n, m / 2) * bin(n, m / 2) * n;
}

int main() {
    int n, m;

    cin >> n >> m;

    cout << bin(n, m);
}