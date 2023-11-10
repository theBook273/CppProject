#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, a[100][100], maxSum = 0, step[100][100];

int moveX[] = {0, 1, 0, -1};
int moveY[] = {1, 0, -1, 0};

void bfsMaxSum(int x, int y) {
    bool check[100][100];
    int sum = 0;
    queue<int> tempX;
    queue<int> tempY;

    tempX.push(x);
    tempY.push(y);

    while (!tempX.empty() && !tempY.empty()) {
        int posx = tempX.front(), posy = tempY.front();
        tempX.pop(), tempY.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = posx + moveX[i], nextY = posy + moveY[i];

            bool checkX = (nextX < n && nextX >= 0),
                 checkY = (nextY < m && nextY >= 0);

            if (checkX && checkY && check[nextX][nextY] == 0 &&
                a[nextX][nextY] == 1) {
                check[nextX][nextY] = 1;
                tempX.push(nextX);
                tempY.push(nextY);
                sum++;
            }
        }
    }

    maxSum = max(sum, maxSum);
    return sum;
}

void bfs(int x, int y) {
    queue<int> tempX;
    queue<int> tempY;

    tempX.push(x);
    tempY.push(y);

    while (!tempX.empty() && !tempY.empty()) {
        int posx = tempX.front(), posy = tempY.front();

        if (a[posx][posy] == 1 && bfsMaxSum(posx, posy) == maxSum) {
        }

        tempX.pop(), tempY.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = posx + moveX[i], nextY = posy + moveY[i];

            bool checkX = (nextX < n && nextX >= 0),
                 checkY = (nextY < m && nextY >= 0);

            if (checkX && checkY &&
                step[nextX][nextY] <= step[posx][posy] + 1 &&
                a[nextX][nextY] == 1) {
                step[nextX][nextY] = step[posx][posy] + 1;
                tempX.push(nextX);
                tempY.push(nextY);
            }
        }
    }
}

int main() {
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                bfsMaxSum(i, j);
            }
        }
    }
}