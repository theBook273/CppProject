#include <bits/stdc++.h>

using namespace std;

pair<int, int> moveSet[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string moveChar[] = {"D", "R", "U", "L"};
int n, a[1000][1000];
bool checked[1000][1000];
string temp;
set<string> se;

void moving(int x, int y) {
    if (x == n - 1 && y == n - 1) {
        se.insert(temp);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int tempx, tempy;
        tempx = x + moveSet[i].first;
        tempy = y + moveSet[i].second;

        if (tempx >= 0 && tempy >= 0 && tempx < n && tempy < n &&
            a[tempx][tempy] == 1 && checked[tempx][tempy] == 0) {
            checked[tempx][tempy] = 1;
            temp += moveChar[i];
            // cout << temp << endl;
            moving(tempx, tempy);
            checked[tempx][tempy] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            checked[i][j] = 0;
        }
    }

    checked[0][0] = 1;
    moving(0, 0);

    if (se.empty()) {
        cout << -1;
        return 0;
    }

    for (auto i : se) {
        cout << i << endl;
    }
}