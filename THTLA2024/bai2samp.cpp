#include <bits/stdc++.h>
using namespace std;

int N, k;
vector<int> x;

bool check(int D) {
    int count = 0;
    int current = 0;
    while (current < N) {
        count++;
        int target = x[current] + D;
        auto j =
            upper_bound(x.begin() + current, x.end(), target) - x.begin() - 1;
        current = upper_bound(x.begin() + j, x.end(), x[j] + D) - x.begin();
    }
    return count <= k;
}

int main() {
    // ifstream fin("BUS.INP");
    // ofstream fout("BUS.OUT");
    cin >> N >> k;
    x.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    int left = 0, right = x.back() - x[0];
    int Y = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            Y = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << Y << endl;
    return 0;
}