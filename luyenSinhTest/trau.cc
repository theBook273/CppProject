#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp", "r", stdin)
#define OUTPUT freopen("draft.out", "w", stdout)
#define FOR(i, l, r) for (auto i = l; i <= r; i++)
#define REP(i, l, r) for (auto i = l; i < r; i++)
#define FORD(i, l, r) for (auto i = l; i >= r; i--)
#define REPD(i, l, r) for (auto i = l; i > r; i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int, int> ii;

const int inf = 1e9;
const int MOD = 1e9 + 7;
const double PI = 3.14159265359;
const int N = 1e5 + 10;

template <class T> bool minimize(T &x, T y) {
  if (x > y)
    x = y;
  else
    return 0;
  return 1;
}
template <class T> bool maximize(T &x, T y) {
  if (x < y)
    x = y;
  else
    return 0;
  return 1;
}

ll S[N << 2], sum[N << 2][2];
int laz[N << 2][2], c[N << 2];
ii h[N << 2][2], ma[N << 2][2], mi[N << 2][2];

int n, m, a[N][2], gold[2], q[N][4];
void lazyupdate(int node, int L, int R) {
  if (!c[node])
    return;
  FOR(type, 0, 1) if (h[node][type].Y) {
    ma[node][type].X = mi[node][type].X = h[node][type].X;
    sum[node][type] = 1LL * h[node][type].X * c[node];
    S[node] = 1LL * h[node][type].X * sum[node][type ^ 1];
    if (L < R) {
      h[node * 2][type] = h[node * 2 + 1][type] = h[node][type];
      laz[node * 2][type] = laz[node * 2 + 1][type] = 0;
    }
    h[node][type] = ii(0, 0);
  }
  S[node] += sum[node][1] * laz[node][0] + sum[node][0] * laz[node][1] +
             1LL * laz[node][0] * laz[node][1] * c[node];
  FOR(i, 0, 1) if (laz[node][i]) {
    sum[node][i] += 1LL * laz[node][i] * c[node];
    ma[node][i].X += laz[node][i];
    mi[node][i].X += laz[node][i];
    if (L < R) {
      laz[node * 2][i] += laz[node][i];
      laz[node * 2 + 1][i] += laz[node][i];
    }
    laz[node][i] = 0;
  }
}
void getinfo(int node) {
  FOR(type, 0, 1) {
    mi[node][type] = (mi[node << 1][type].X < mi[node * 2 + 1][type].X)
                         ? mi[node * 2][type]
                         : mi[node * 2 + 1][type];
    ma[node][type] = (ma[node << 1][type].X > ma[node * 2 + 1][type].X)
                         ? ma[node * 2][type]
                         : ma[node * 2 + 1][type];
    sum[node][type] = (sum[node << 1][type] + sum[node * 2 + 1][type]);
  }
  c[node] = c[node * 2] + c[node * 2 + 1];
  S[node] = S[node * 2] + S[node * 2 + 1];
}
void update(int type, int node, int L, int R, int l, int r, int v) {
  lazyupdate(node, L, R);
  if (L > r || R < l)
    return;
  if (l <= L && R <= r) {
    if (type > 2)
      laz[node][type - 3] += v;
    else
      h[node][type - 1] = ii(v, 1);
    lazyupdate(node, L, R);
    return;
  }
  update(type, node * 2, L, (L + R) / 2, l, r, v);
  update(type, node * 2 + 1, (L + R) / 2 + 1, R, l, r, v);
  getinfo(node);
}
ll query(int type, int node, int L, int R, int l, int r) {
  lazyupdate(node, L, R);
  if (L > r || R < l)
    return 0;
  if (l <= L && R <= r)
    return (type ? c[node] : S[node]);
  return query(type, node * 2, L, (L + R) / 2, l, r) +
         query(type, node * 2 + 1, (L + R) / 2 + 1, R, l, r);
}
void clearnode(int node) {
  FOR(i, 0, 1) {
    mi[node][i].X = inf;
    ma[node][i].X = -inf;
    h[node][i] = ii(0, 0);
    laz[node][i] = 0;
    sum[node][i] = 0;
  }
  c[node] = S[node] = 0;
}
void erase(int node, int L, int R, int x) {
  lazyupdate(node, L, R);
  if (L > x || R < x)
    return;
  if (L == R) {
    clearnode(node);
    return;
  }
  erase(node * 2, L, (L + R) / 2, x);
  erase(node * 2 + 1, (L + R) / 2 + 1, R, x);
  getinfo(node);
}
void build(int node, int L, int R) {
  if (L == R) {
    bool ok = !(a[L][0] > gold[0] || a[L][1] > gold[1] || a[L][0] <= 0 ||
                a[L][1] <= 0);
    FOR(i, 0, 1) {
      mi[node][i] = ii(ok ? a[L][i] : inf, L);
      ma[node][i] = ii(ok ? a[L][i] : -inf, L);
      sum[node][i] = ok ? a[L][i] : 0;
    }
    c[node] = ok;
    S[node] = ok ? 1LL * a[L][0] * a[L][1] : 0;
    return;
  }
  build(node * 2, L, (L + R) / 2);
  build(node * 2 + 1, (L + R) / 2 + 1, R);
  getinfo(node);
}
void detect() {
  FOR(type, 0, 1) {
    while (ma[1][type].X > gold[type]) {
      int x = ma[1][type].Y;
      erase(1, 1, n, x);
    }
    while (mi[1][type].X <= 0) {
      int x = mi[1][type].Y;
      erase(1, 1, n, x);
    }
  }
}
void check(int node, int L, int R) {
  printf("%d %d %d\n", node, L, R);
  //    printf("Max a:%d %d\n",ma[node][0].X,ma[node][0].Y);
  //    printf("Min a:%d %d\n",mi[node][0].X,mi[node][0].Y);
  //    printf("Max b:%d %d\n",ma[node][1].X,ma[node][1].Y);
  //    printf("Min b:%d %d\n",mi[node][1].X,mi[node][1].Y);
  printf("%d %d\n", laz[node][0], laz[node][1]);
  cout << sum[node][0] << " " << sum[node][1] << '\n' << S[node] << '\n';
  if (L == R)
    return;
  check(node * 2, L, (L + R) / 2);
  check(node * 2 + 1, (L + R) / 2 + 1, R);
}
int main() {
  freopen("test.inp", "r", stdin);
  freopen("testTrau.out", "w", stdout);
  //    INPUT;OUTPUT;
  scanf("%d%d", &n, &m);
  FOR(i, 1, n)
  FOR(j, 0, 1) scanf("%d", a[i] + j);
  FOR(i, 1, m) {
    FOR(j, 0, 2) scanf("%d", q[i] + j);
    if (q[i][0] <= 4)
      scanf("%d", q[i] + 3);
  }
  scanf("%d%d", gold, gold + 1);
  build(1, 1, n);
  //    check(1,1,n);
  FOR(i, 1, m) {
    //        printf("%d...\n",i);
    if (q[i][0] <= 4)
      update(q[i][0], 1, 1, n, q[i][1], q[i][2], q[i][3]);
    else {
      detect();
      printf("%lld\n", query(q[i][0] - 5, 1, 1, n, q[i][1], q[i][2]));
    }
    //        check(1,1,n);
  }
}
