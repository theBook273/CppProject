#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main() {
    int n;

    cin >> n;

    pair<int, int> a[n];

    for (auto &i : a) {
        cin >> i.first >> i.second;
    }

    sort(a, a + n, comp);

    for (auto i : a) {
        cout << i.first << " " << i.second << endl;
    }
}
