#include <bits/stdc++.h>

using namespace std;

int n, d, arr[1000000], queries;

void check(deque<int> temp) {
    for (auto i : temp) {
        cout << i << " ";
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < d; i++) {
        cin >> queries;

        int res = 1e9, r = 0;
        deque<int> a;

        for (int j = 0; j < n; j++) {
            while (!a.empty() && arr[a.back()] < arr[j]) {
                a.pop_back();
            }

            a.push_back(j);

            while (!a.empty() && a.front() <= j - queries) {
                a.pop_front();
            }

            if (j - queries >= -1 && !a.empty()) {
                res = min(res, arr[a.front()]);
            }
        }

        cout << res << endl;
    }
}
