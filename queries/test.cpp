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

        deque<int> a;
        int minRes = 1e9, subMax = 0, tempMax, r = 0;

        for (int j = 0; j < n; j++) {
            if (j - r + 1 <= queries) {
            }
            if (j - r + 1 == queries) {
                minRes = min(minRes, subMax);

                subMax = 0;

                r++;
            }
        }

        cout << minRes << endl;
    }
}
