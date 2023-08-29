#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> one, two, both;

        for (int i = 0; i < n; i++) {
            int time;

            string skill;

            cin >> time >> skill;

            if (skill == "10") {
                one.push_back(time);
            } else if (skill == "01") {
                two.push_back(time);
            } else if (skill == "11") {
                both.push_back(time);
            }
        }

        int tong = 1e9;

        if (!one.empty() && !two.empty()) {
            tong = *min_element(two.begin(), two.end()) +
                   *min_element(one.begin(), one.end());
        }
        if (!both.empty()) {
            tong = min(tong, *min_element(both.begin(), both.end()));
        }

        cout << ((tong == 1e9) ? -1 : tong) << endl;
    }
}