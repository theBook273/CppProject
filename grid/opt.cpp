#include <bits/stdc++.h>
#define int long long

using namespace std;

map<char, pair<int, int>> moveset = {
    {'D', {1, 0}}, {'U', {-1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
bool board[9][9];

string s;
int step = 0, tong = 0;

void dfs(int x, int y, char dir) {
    if (x == 7 && y == 1 && step < 48) return;

    if (x == 7 && y == 1 && step == 48) {
        ++tong;
        return;
    }

    if (dir != ' ') {
        int tempx = x + moveset[dir].first;
        int tempy = y + moveset[dir].second;
        if (board[tempx][tempy]) {
            pair<int, int> side1, side2;
            if (dir == 'U' || dir == 'D') {
                side1 = moveset['L'];
                side2 = moveset['R'];
            } else {
                side1 = moveset['U'];
                side2 = moveset['D'];
            }

            if (!board[x + side1.first][y + side1.second] &&
                !board[x + side2.first][y + side2.second]) {
                return;
            }
        }
    }

    if (!board[x][y]) {
        board[x][y] = 1;
        step++;
        if (s[step - 1] == '?') {
            for (auto i : moveset) {
                int nx = x + i.second.first;
                int ny = y + i.second.second;
                dfs(nx, ny, i.first);
            }
        } else {
            int nx = x + moveset[s[step - 1]].first;
            int ny = y + moveset[s[step - 1]].second;
            dfs(nx, ny, s[step - 1]);
        }
        board[x][y] = 0;
        step--;
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> s;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) board[i][j] = 1;

    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 7; j++) board[i][j] = 0;

    dfs(1, 1, ' ');

    cout << tong;
}