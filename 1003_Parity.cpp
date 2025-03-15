#include <bits/stdc++.h>
using namespace std;

#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

//============================================================================
// START PROGRAM
//============================================================================
// DSU for Competitive programming
long long N = 0;
map<long long, long long> parent, deg, tracker;

long long search(long long x) {
    return x == parent[x] ? x : parent[x] = search(parent[x]);
}
void join(long long x, long long y) {
    x = search(x), y = search(y);
    // Retain for u = max(search(x), search(y)); v = min(search(x), search(y));
    if (x != y) {
        if (deg[x] < deg[y]) swap(x, y);
        parent[y] = x;
        deg[x] += deg[y];
    }
}
// Finish DSU
long long i, Q, distanceForNegative, ck;

void init() {
    parent.clear();
    deg.clear();
    tracker.clear();
}

int main() {
    fast_io;
    cin >> ck;
    while (ck != -1) {
        N = ck;
        cin >> Q;
        long long leftVal[8008], rightVal[8008];
        string queryAns[8008];

        for (i = 1; i <= Q; i++) {
            cin >> leftVal[i] >> rightVal[i] >> queryAns[i];
        }

        init();
        distanceForNegative = N + 8;
        i = 1;
        for (; i <= Q; i++) {
            leftVal[i]--;
            if (!tracker.count(leftVal[i])) {
                tracker[leftVal[i]] = 1;
                parent[leftVal[i]] = leftVal[i];
                parent[leftVal[i] + distanceForNegative] =
                    leftVal[i] + distanceForNegative;
                deg[leftVal[i]] = deg[leftVal[i] + distanceForNegative] = 1;
            }
            if (!tracker.count(rightVal[i])) {
                tracker[rightVal[i]] = 1;
                parent[rightVal[i]] = rightVal[i];
                parent[rightVal[i] + distanceForNegative] =
                    rightVal[i] + distanceForNegative;
                deg[rightVal[i]] = deg[rightVal[i] + distanceForNegative] = 1;
            }

            if (queryAns[i] == "even") {
                join(leftVal[i], rightVal[i]);
                join(leftVal[i] + distanceForNegative,
                     rightVal[i] + distanceForNegative);
            } else {
                join(leftVal[i], rightVal[i] + distanceForNegative);
                join(rightVal[i], leftVal[i] + distanceForNegative);
            }
            // Remember that if start item < 1 or end iterator > N it is also a
            // lie by the replier so we break rightaway and cout the line it lie
            if ((leftVal[i] < 0) || (rightVal[i] > N) ||
                (search(leftVal[i]) ==
                 search(leftVal[i] + distanceForNegative)) ||
                (search(rightVal[i]) ==
                 search(rightVal[i] + distanceForNegative)))
                break;
        }

        if (N != -1) cout << i - 1 << "\n";

        cin >> ck;
    }
    // getchar();
}