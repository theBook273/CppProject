#include <bits/stdc++.h>

using namespace std;

long long soUoc(long long n) {
    long long demMu = 0, demUoc = 1;
    for (long long i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            n /= i;
            demMu++;
        }
        demUoc *= demMu + 1;
        demMu = 0;
    }
    if (n != 1) return demUoc * 2;
    return demUoc;
}

signed main() {
    long long t, n;

    cin >> n;

    t = n * (n + 1) * (n + 2);

    long long temp = sqrt(t);

    if (temp * temp == t) {
        cout << 0;
        return 0;
    }

    cout << soUoc(t) << endl;
    cout << soUoc(t * t) << endl;
}