#include <bits/stdc++.h>

using namespace std;

long long n, m, board[1000][1000];
pair<long long, long long> temp[1000], res1, res2;

bool comp(pair<long long, long long> x, pair<long long, long long> y) {
    return x > y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        temp[i] = {board[0][i], i};
    }

    sort(temp, temp + m, comp);

    res1 = temp[0];
    res2 = temp[1];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res1.second != j)
                temp[j] = {board[i][j] + res1.first, j};

            else
                temp[j] = {board[i][j] + res2.first, j};
        }
        sort(temp, temp + m, comp);
        res1 = temp[0];
        res2 = temp[1];
    }

    cout << max(res1.first, res2.first);
}