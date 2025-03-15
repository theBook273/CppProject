#include <bits/stdc++.h>

using namespace std;

class solution {
   private:
    long long n, k, bac = 0, tong = 0;

   public:
    solution() { cin >> n >> k; }

    void solve() {
        if (k == 1) {
            cout << n - 1 << " " << n << endl;
            return;
        }
        while (tong < n) {
            tong += pow(k, bac);
            bac++;
        }

        bac--;

        cout << bac << " " << tong << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        solution a;
        a.solve();
    }
}
