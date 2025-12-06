#include <bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair<ll, int>
#define iii pair<int, ii>
#define iv pair<ii, ii>

#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()

#define FOR(i, x, n) for (int i = x; i <= n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i, x, n) for (int i = x; i >= n; --i)

#define ll long long
#define oo 1e9
#define pow poww

const int N = 1e5 + 5;
int n, m, cnt, ans = oo, res, res1 = 0, ssc;
int d[N], low[N], sz[N], par[N], f[N];
vector<int> g[N];
bool khop[N];
map<int, vector<iii>> X, Y;
iv a[N];

int acs(int u) {
  if (par[u] == u)
    return u;
  else
    return par[u] = acs(par[u]);
}

void join(int u, int v) {
  int x = acs(u);
  int y = acs(v);
  if (x != y) {
    ssc--;
    f[y] += f[x];
    par[x] = y;
  }
}

void DFS(int i, int j) {
  low[i] = d[i] = ++cnt;
  sz[i] = 1;
  REP(s, g[i].size()) {
    int u = g[i][s];
    if (u != j) {
      if (d[u])
        low[i] = min(low[i], d[u]);
      else {
        DFS(u, i);
        low[i] = min(low[i], low[u]);
        sz[i] += sz[u];
        if (low[u] >= d[u]) {
          // cout << u << " " << sz[u] << endl;
          ans = min(ans, abs(sz[u] - (f[acs(u)] - sz[u])));
          res++;
        }
      }
    }
  }
}

bool cmp(iii a, iii b) { return a.se.fi < b.se.fi; }

set<ii> edge;

signed main() {
  // freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
    swap(a[i].fi.se, a[i].se.se);
    X[a[i].fi.fi].push_back(iii(i, ii(a[i].fi.se, a[i].se.se)));
    X[a[i].se.fi].push_back(iii(i, ii(a[i].fi.se, a[i].se.se)));

    Y[a[i].fi.se].push_back(iii(i, ii(a[i].fi.fi, a[i].se.fi)));
    Y[a[i].se.se].push_back(iii(i, ii(a[i].fi.fi, a[i].se.fi)));
  }
  FOR(i, 1, n)
  par[i] = i, f[i] = 1;

  for (auto it = X.begin(); it != X.end(); it++) {
    int x = it->first;
    multiset<ii> st;
    st.clear();
    sort(X[x].begin(), X[x].end(), cmp);
    // cout << x << endl;
    for (int i = 0; i < X[x].size(); i++) {
      while (!st.empty()) {
        auto it = st.begin();
        ii y = *(it);
        // cout << y.first << "." <<  X[x][i].se.fi << endl;
        if (y.first < X[x][i].se.fi)
          st.erase(it);
        else
          break;
      }
      for (auto it = st.begin(); it != st.end(); it++) {
        ii y = *(it);
        int a = y.se;
        int b = X[x][i].fi;
        if (a > b)
          swap(a, b);
        if (edge.find(ii(a, b)) == edge.end()) {
          edge.insert(ii(a, b));
          // cout << y.se << " " << X[x][i].fi << endl;
          g[a].push_back(b);
          g[b].push_back(a);
          join(a, b);
        }
      }
      st.insert(ii(X[x][i].se.se, X[x][i].fi));
    }
  }

  for (auto it = Y.begin(); it != Y.end(); it++) {
    int x = it->first;
    multiset<ii> st;
    st.clear();
    sort(Y[x].begin(), Y[x].end(), cmp);
    // cout << x << endl;
    for (int i = 0; i < Y[x].size(); i++) {
      while (!st.empty()) {
        auto it = st.begin();
        ii y = *(it);
        // cout << y.first << "." <<  Y[x][i].se.fi << endl;
        if (y.first < Y[x][i].se.fi)
          st.erase(it);
        else
          break;
      }
      for (auto it = st.begin(); it != st.end(); it++) {
        ii y = *(it);
        int a = y.se;
        int b = Y[x][i].fi;
        if (a > b)
          swap(a, b);
        if (edge.find(ii(a, b)) == edge.end()) {
          edge.insert(ii(a, b));
          // cout << y.se << " " << X[x][i].fi << endl;
          g[a].push_back(b);
          g[b].push_back(a);
          join(a, b);
        }
      }
      st.insert(ii(Y[x][i].se.se, Y[x][i].fi));
    }
  }
  FOR(i, 1, n)
  if (!d[i])
    DFS(i, -1);
  if (ans == oo)
    cout << "-1";
  else
    cout << ans;
}
