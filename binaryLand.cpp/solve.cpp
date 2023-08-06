#include <bits/stdc++.h>

using namespace std;
int n, q;

class theCity {
   private:
    deque<string> land;
    int board[28][28];

   public:
    theCity() {
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 28; j++) {
                board[i][j] = 0;
            }
        }
    }

    void add(string rowToAdd) { land.push_back(rowToAdd); }

    void remove() { land.pop_front(); }

    void path(int start, int end) {
        pair<int, int> moveSet[] = {{1, -1}, {1, 0}, {1, 1}};

        if (land[0][start - 1] != land[land.size() - 1][end - 1]) {
            cout << 0 << endl;
            return;
        }

        if (land.size() == 1) {
            cout << 0 << endl;
            return;
        }

        char example = land[0][start - 1];

        queue<pair<int, int>> locAtMoment;
        locAtMoment.push({0, start - 1});

        while (!locAtMoment.empty()) {
            pair<int, int> temp = locAtMoment.front();
            locAtMoment.pop();

            if (temp.first == land.size() - 1 && temp.second == end - 1) {
                board[land.size() - 1][end - 1] %= 1000000007;
                board[land.size() - 1][end - 1]++;
            }

            for (auto i : moveSet) {
                int moX = temp.first + i.first, moY = temp.second + i.second;

                if (moX < land.size() && moY < n) {
                    if (land[moX][moY] == example) {
                        locAtMoment.push({moX, moY});
                    }
                }
            }
        }

        cout << board[land.size() - 1][end - 1] << endl;
    }

    void test() {
        for (auto i : land) {
            cout << i << endl;
        }

        cout << endl << endl;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("land.txt", "w", stdout);

    theCity city;

    cin >> n >> q;

    while (q--) {
        string temp;

        cin >> temp;

        if (temp == "add") {
            string tempA;

            cin >> tempA;

            city.add(tempA);

        } else if (temp == "remove") {
            city.remove();

        } else if (temp == "path") {
            int temp1, temp2;

            cin >> temp1 >> temp2;

            city.path(temp1, temp2);
        }
    }
}