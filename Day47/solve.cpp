#include <bits/stdc++.h>
using namespace std;

long long tong(long long n) {
    if (n == 0) return 0;
    return 2 * ((1LL << n) - 1);
}

void tobin(long long x, long long si) {
    stack<long long> st;
    while (x) {
        st.push(x % 2);
        x /= 2;
    }
    while (st.size() < si) {
        st.push(0);
    }
    while (!st.empty()) {
        if (st.top() == 0) {
            cout << 4;
        } else {
            cout << 7;
        }
        st.pop();
    }
    cout << endl;
}

long long main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;

        long long l = 0, r = 20, t_val = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (tong(mid) < n) {
                t_val = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ++t_val;
        long long remain = n - pow(2, (t_val)) + 1;
        tobin(remain, t_val);
    }
    return 0;
}
