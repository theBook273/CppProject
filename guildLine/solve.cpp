#include <bits/stdc++.h>

using namespace std;
long long n, k, c;

vector<long long> x;
vector<long long> y;

long long main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    x.push_back(-2e9);
    y.push_back(-2e9);

    cin >> n >> k >> c;

    for (long long i = 0; i < n; i++) {
        long long stt;

        cin >> stt;

        if (stt == 0) {
            long long temp;

            cin >> temp;

            x.push_back(temp);
        }

        if (stt == 1) {
            long long temp;

            cin >> temp;

            y.push_back(temp);
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    x.push_back(3e9);
    y.push_back(3e9);

    for (long long i = 0; i < k; i++) {
        long long dx, dy, dx1, dy1;

        cin >> dx >> dy >> dx1 >> dy1;

        long long u1 = upper_bound(x.begin(), x.end(), dx) - x.begin() - 1;
        long long d1 = lower_bound(x.begin(), x.end(), dx1) - x.begin();
        long long u2 = upper_bound(y.begin(), y.end(), dy) - y.begin() - 1;
        long long d2 = lower_bound(y.begin(), y.end(), dy1) - y.begin();

        if (-x[u1] + dx <= c || x[d1] - dx1 <= c || -y[u2] + dy <= c ||
            y[d2] - dy1 <= c) {
            cout << "YES";
        } else
            cout << "NO";

        cout << "\n";
    }
}
