#include <bits/stdc++.h>

using namespace std;
int n, q;

deque<string> land;

void add(string rowToAdd) { land.push_back(rowToAdd); }

void remove() { land.pop_front(); }

void path(int start, int end) {
    long long cach = 0;
    pair<int, int> moveSet[] = {{1, -1}, {1, 0}, {1, 1}};

    if (land[0][start - 1] != land[land.size() - 1][end - 1]) {
        cout << 0 << endl;
        return;
    }

    if (land.size() == 1) {
        cout << 0 << endl;
        return;
    }

    queue<pair<int, int>> locAtMoment;
    locAtMoment.push({0, start - 1});

    while (!locAtMoment.empty()) {
        pair<int, int> temp = locAtMoment.front();
        locAtMoment.pop();

        if (temp.first == land.size() - 1 && temp.second == end - 1) {
            cach++;
            cach %= 1000000007;
        }

        for (auto i : moveSet) {
            int moX = temp.first + i.first, moY = temp.second + i.second;

            if (moX < land.size() && moY < n) {
                if (land[moX][moY] == land[temp.first][temp.second]) {
                    locAtMoment.push({moX, moY});
                }
            }
        }
    }

    cout << cach << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("land.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    while (q--) {
        string temp;

        cin >> temp;

        if (temp == "add") {
            string tempA;

            cin >> tempA;

            add(tempA);

        } else if (temp == "remove") {
            remove();

        } else if (temp == "path") {
            int temp1, temp2;

            cin >> temp1 >> temp2;

            path(temp1, temp2);
        }
    }
}