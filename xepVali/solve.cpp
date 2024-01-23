#include <bits/stdc++.h>

using namespace std;

int n, w;

map<int, int> tempChosenTimes, resChosen;

pair<pair<int, double>, pair<int, int>> spcAndVal[10000];
pair<int, int> maxSpcAndVal = {0, 0}, res = {0, 0};

bool comp(pair<pair<int, double>, pair<int, int>> a,
          pair<pair<int, double>, pair<int, int>> b) {
    return a.first.second > b.first.second;
}

void solve() {
    if (maxSpcAndVal.first <= w) {
        if (res.second < maxSpcAndVal.second) {
            res = maxSpcAndVal;
            cout << res.second << endl;
            resChosen = tempChosenTimes;
        }
    }

    for (int i = 0; i < n; i++) {
        if (maxSpcAndVal.first + spcAndVal[i].second.first <= w) {
            maxSpcAndVal.first += spcAndVal[i].second.first;
            maxSpcAndVal.second += spcAndVal[i].second.second;
            tempChosenTimes[spcAndVal[i].first.first + 1]++;
            solve();
            maxSpcAndVal.first -= spcAndVal[i].second.first;
            maxSpcAndVal.second -= spcAndVal[i].second.second;
            tempChosenTimes[spcAndVal[i].first.first + 1]--;
            if (tempChosenTimes[spcAndVal[i].first.first + 1] == 0) {
                tempChosenTimes.erase(spcAndVal[i].first.first + 1);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        spcAndVal[i].first.first = i;
        cin >> spcAndVal[i].second.first >> spcAndVal[i].second.second;
        spcAndVal[i].first.second =
            spcAndVal[i].second.second / double(spcAndVal[i].second.first);
    }

    sort(spcAndVal, spcAndVal + n, comp);

    // for (int i = 0; i < n; i++) {
    //     cout << spcAndVal[i].first << " " << spcAndVal[i].second << endl;
    // }

    solve();

    cout << res.second << endl;

    for (auto i : resChosen) {
        cout << i.first << "  " << i.second << endl;
    }
}