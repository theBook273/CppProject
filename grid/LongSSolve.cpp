#include <bits/stdc++.h>

#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
// Define local for input and output files
// #define LOCAL
//============================================================================
// START PROGRAM
//============================================================================

const long long total = 49;
string st;
long long ans = 0;
bool visited[9][9];

// Graph transitions
vector<pair<long long, long long>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
map<char, pair<int, int>> mapDir = {
    {'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
map<char, int> dirOrder = {{'L', 1}, {'R', 0}, {'U', 3}, {'D', 2}};

// Check for Optimization 3 to stop recursion for this path
bool checkCase(long long dirk, long long coorx, long long coory) {
    if (dirk == 0 && visited[coorx][coory + 1] && !visited[coorx - 1][coory] &&
        !visited[coorx + 1][coory])
        return true;
    else if (dirk == 1 && visited[coorx][coory - 1] &&
             !visited[coorx - 1][coory] && !visited[coorx + 1][coory])
        return true;
    else if (dirk == 2 && visited[coorx + 1][coory] &&
             !visited[coorx][coory + 1] && !visited[coorx][coory - 1])
        return true;
    else if (dirk == 3 && visited[coorx - 1][coory] &&
             !visited[coorx][coory + 1] && !visited[coorx][coory - 1])
        return true;
    return false;
}
void solve(long long pos, long long x, long long y) {
    if (x == 7 && y == 1) {
        // If it is the finish of the st string then add to ans as a new path
        if (pos == total) ans++;
        // Optimization 2: Stop if pass the end cell (1,7) before finish the st
        // string return;
    } else if (pos < total && !visited[x][y]) {
        // Optimization 3: Stop if separate board into 2 slides, both contain
        // unvisit cell We won't travel to these cells
        visited[x][y] = true;
        if (st[pos - 1] == '?') {
            for (int k = 0; k < 4; k++) {
                long long vx = x + dir[k].first, vy = y + dir[k].second;
                if (!visited[vx][vy] && !checkCase(k, vx, vy))
                    solve(pos + 1, vx, vy);
            }
        } else {
            long long vx = x + mapDir[st[pos - 1]].first,
                      vy = y + mapDir[st[pos - 1]].second;
            if (!visited[vx][vy] && !checkCase(dirOrder[st[pos - 1]], vx, vy))
                solve(pos + 1, vx, vy);
        }
        visited[x][y] = false;
    }
}

int main() {
    fast_io;
    cin >> st;
    // build fences
    for (int i = 0; i < 9; i++)
        visited[0][i] = visited[i][0] = visited[8][i] = visited[i][8] = true;
    // Prepare for Optimize 1: We just move right or down and double the
    // results, so mark the (1,1) as visited
    solve(1, 1, 1);
    // Solve: Base on st[0] if it is ? or D or R??
    // Solve: Base on st[0] if it is ? or D or R??
    // Solve parameters: (temptRes, pos, x, y)
    // temptRes: Current result counter
    // pos: Current position on st string
    // x, y: Current position on the board

    cout << ans;
    return 0;
}