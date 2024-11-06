#include <bits/stdc++.h>
#define int long long

using namespace std;

int visisted[9][9];
int step(0), tong(0);

vector<char> road;
string s;

map<char, pair<int, int>> direc = {
    {'D', {1, 0}}, {'U', {-1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

pair<pair<int, int>, pair<int, int>> combo[] = {
    {{0, 1}, {1, 0}}, {{-1, 0}, {0, -1}}, {{1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}};
pair<int, int> diag[] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void dfs(int x, int y) {
    if (x == 7 && y == 1 && step < 48) return;

    if (step != 0) {
        if (s[step - 1] != '?' && s[step - 1] != road.back()) return;
    }

    if (!road.empty()) {
        pair<int, int> a = direc[road.back()];
        int tempx = x + a.first;
        int tempy = y + a.second;
        if (visisted[tempx][tempy]) {
            pair<int, int> side1, side2;
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

    for (int i = 0; i < 4; ++i) {
        int nx1 = x + combo[i].first.first;
        int ny1 = y + combo[i].first.second;
        int nx2 = x + combo[i].second.first;
        int ny2 = y + combo[i].second.second;
        int tempx = x + diag[i].first;
        int tempy = y + diag[i].second;

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
        int nx = x + i.second.first;
        int ny = y + i.second.second;
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

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            visisted[i][j] = 1;
        }
    }

    for (int i = 1; i <= 7; ++i) {
        for (int j = 1; j <= 7; ++j) {
            visisted[i][j] = 0;
        }
    }

    visisted[1][1] = 1;
    dfs(1, 1);
    cout << tong;
}