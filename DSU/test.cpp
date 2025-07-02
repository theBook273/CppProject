#include <bits/stdc++.h>

using namespace std;

vector<long long> day[100000];
int res[100000];
vector<long long> cut;
long long n, m, q, parent[100000], ranking[100005];
int ans, lastStand;

long long tim(long long a) {
    if (parent[a] == a) return a;

    return parent[a] = tim(parent[a]);
}

void makeUnion(long long a, long long b) {
    a = tim(a);
    b = tim(b);

    if (a != b) {
        if (ranking[a] < ranking[b]) swap(a, b);
        parent[b] = a;
        if (ranking[a] == ranking[b]) ranking[a]++;
        ans--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    ans = n;

    for (long long i = 1; i <= n; i++) {
        parent[i] = i;
        ranking[i] = 1;
    }

    for (long long i = 1; i <= m; i++) {
        long long a, b;

        cin >> a >> b;

        day[i].push_back(a);
        day[i].push_back(b);
    }

    cin >> q;

    lastStand = q;

    while (q--) {
        long long temp;

        cin >> temp;

        cut.push_back(temp);

        day[temp].push_back(-1);
    }

    for (long long i = 1; i <= m; i++) {
        if (day[i].back() != -1) {
            makeUnion(day[i].front(), day[i].back());
        }
    }

    long long dem = cut.size();

    while (dem - 1 >= 0) {
        res[dem - 1] = ans;

        makeUnion(day[cut.back()][0], day[cut.back()][1]);

        cut.pop_back();
        dem--;
    }

    for (int i = 0; i < lastStand; i++) {
        cout << res[i] << " ";
    }
}