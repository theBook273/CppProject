#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long visisted[9][9];
long long step(0), tong(0);

vector<char> road;
string s;

map<char, pair<long long, long long>> direc = {
    {'D', {1, 0}}, {'U', {-1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

pair<pair<long long, long long>, pair<long long, long long>> combo[] = {
    {{0, 1}, {1, 0}}, {{-1, 0}, {0, -1}}, {{1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}};
pair<long long, long long> diag[] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void dfs(long long x, long long y) {
    if (x == 7 && y == 1 && step < 48) return;

    if (step != 0) {
        if (s[step - 1] != '?' && s[step - 1] != road.back()) return;
    }

    if (!road.empty()) {
        pair<long long, long long> a = direc[road.back()];
        long long tempx = x + a.first;
        long long tempy = y + a.second;
        if (visisted[tempx][tempy]) {
            pair<long long, long long> side1, side2;
            if (road.back() == 'U' || road.back() == 'D') {
                side1 = direc['L'];
                side2 = direc['R'];
            } else {
                side1 = direc['U'];
                side2 = direc['D'];
            }

            if (!visisted[x + side1.first][y + side1.second] &&
                !visisted[x + side2.first][y + side2.second]) {
                return;
            }
        }
    }

    for (long long i = 0; i < 4; ++i) {
        long long nx1 = x + combo[i].first.first;
        long long ny1 = y + combo[i].first.second;
        long long nx2 = x + combo[i].second.first;
        long long ny2 = y + combo[i].second.second;
        long long tempx = x + diag[i].first;
        long long tempy = y + diag[i].second;

        if (visisted[tempx][tempy] == 2 &&
            (!visisted[nx1][ny1] && !visisted[nx2][ny2])) {
            return;
        }
    }

    if (step == 48 && x == 7 && y == 1) {
        ++tong;
        return;
    }

    for (auto i : direc) {
        long long nx = x + i.second.first;
        long long ny = y + i.second.second;
        if (!visisted[nx][ny]) {
            road.push_back(i.first);
            ++step;
            visisted[nx][ny] = 2;
            dfs(nx, ny);
            road.pop_back();
            --step;
            visisted[nx][ny] = 0;
        }
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> s;

    for (long long i = 0; i < 9; ++i) {
        for (long long j = 0; j < 9; ++j) {
            visisted[i][j] = 1;
        }
    }

    for (long long i = 1; i <= 7; ++i) {
        for (long long j = 1; j <= 7; ++j) {
            visisted[i][j] = 0;
        }
    }

    visisted[1][1] = 1;
    dfs(1, 1);
    cout << tong;
}
