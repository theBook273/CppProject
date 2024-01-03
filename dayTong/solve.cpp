#include <bits/stdc++.h>

using namespace std;
int n, k, a[100000], tong = 0;
vector<int> s;
vector<vector<int>> res;

void duyet(int x) {
    if (tong == k) {
        sort(s.begin(), s.end());
        res.push_back(s);
        return;
    }

    for (int i = x + 1; i < n; i++) {
        if (tong + a[i] <= k) {
            tong += a[i];
            s.push_back(a[i]);
            duyet(i);
            tong -= a[i];
            s.pop_back();
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    duyet(0);

    sort(res.begin(), res.end());

    for (auto i : res) {
        cout << "[";
        for (int j = 0; j < i.size(); j++) {
            cout << i[j];
            if (j + 1 < i.size()) cout << " ";
        }

        cout << "]" << endl;
    }
}