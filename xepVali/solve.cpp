#include <bits/stdc++.h>

using namespace std;

long long n, w;

map<long long, long long> tempChosenTimes, resChosen;

pair<pair<long long, double>, pair<long long, long long>> spcAndVal[10000];
pair<long long, long long> maxSpcAndVal = {0, 0}, res = {0, 0};

bool comp(pair<pair<long long, double>, pair<long long, long long>> a,
          pair<pair<long long, double>, pair<long long, long long>> b) {
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

    for (long long i = 0; i < n; i++) {
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

long long main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> w;
    for (long long i = 0; i < n; i++) {
        spcAndVal[i].first.first = i;
        cin >> spcAndVal[i].second.first >> spcAndVal[i].second.second;
        spcAndVal[i].first.second =
            spcAndVal[i].second.second / double(spcAndVal[i].second.first);
    }

    sort(spcAndVal, spcAndVal + n, comp);

    // for (long long i = 0; i < n; i++) {
    //     cout << spcAndVal[i].first << " " << spcAndVal[i].second << endl;
    // }

    solve();

    cout << res.second << endl;

    for (auto i : resChosen) {
        cout << i.first << "  " << i.second << endl;
    }
}
