/**
 *    author:       _minhduc
 *    created:      17-10-2025 21:09:29
 **/

#include <bits/stdc++.h>
#define taskname ""
#define int long long

using namespace std;

const int MAX_N = 1'000'000;

int n, k, res = 0, times = 0;
int sz[MAX_N + 5], in[MAX_N + 5], out[MAX_N + 5], pos[MAX_N + 5],
    depth[MAX_N + 5], cnt[MAX_N + 5];
vector<int> adj[MAX_N + 5];

void calc(int u, int p) {
  sz[u] = 1;
  times++;
  in[u] = times;
  pos[times] = u;
  for (int v : adj[u]) {
    if (v == p)
      continue;
    depth[v] = depth[u] + 1;
    calc(v, u);
    sz[u] += sz[v];
  }
  out[u] = times;
}

void dfs(int u, int p, int isBig) {
  int bigChild = -1;
  // Tìm con lớn nhất
  for (int v : adj[u])
    if (v != p && (bigChild == -1 || sz[v] > sz[bigChild]))
      bigChild = v;
  // Thăm các "con nhỏ" trước
  for (int v : adj[u]) {
    if (v == p || v == bigChild)
      continue;
    dfs(v, u, 0);
  }
  if (bigChild != -1)
    dfs(bigChild, u, 1);

  // cnt[d]: dếm số đỉnh hiện đang có trong sack với depth (tính từ gốc) = d
  res += cnt[k + depth[u]];
  cnt[depth[u]]++;
  for (int v : adj[u]) {
    if (v == p || v == bigChild)
      continue;

    // Đếm các đỉnh đã có trong sack từ trước với các đỉnh nằm trong
    // cây con gốc v
    for (int i = in[v]; i <= out[v]; i++) {
      // in[v] -> out[v]: thứ tứ tất cả các đỉnh nằm trong cây con gốc v
      int d = k + 2 * depth[u] - depth[pos[i]];
      if (d >= 0)
        res += cnt[d];
    }

    // Thêm tất cả các đỉnh trong cây con gốc v vào sack
    for (int i = in[v]; i <= out[v]; i++)
      cnt[depth[pos[i]]]++;
  }

  // Nếu như đây không phải "con lớn"
  // loại bỏ tất cả các đỉnh khỏi cây con gốc u trong sack (không giữ lại)
  // Nếu không -> bị duplicate khi duyệt cha
  if (!isBig)
    for (int i = in[u]; i <= out[u]; i++)
      cnt[depth[pos[i]]]--;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen(".inp", "r", stdin);
  freopen(".out", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
  // freopen(taskname".inp", "r", stdin);
  // freopen(taskname".out", "w", stdout);
#endif
  cin >> n >> k;
  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // DFS lần 1
  // Mục đích: Tìm size của cây con gốc u và thứ tự của Euler tour.
  calc(1, -1);
  dfs(1, -1, 1);
  cout << res;
}
