#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int from, to;
};

struct Query {
  char type;
  int x, y;
};

int n, m, q;
vector<int> a;
vector<Edge> edges;
vector<Query> queries;

int bfs_sum(int start, vector<vector<int>> &adj, vector<int> &a,
            vector<int> &vis) {
  queue<int> qu;
  qu.push(start);
  vis[start] = 1;
  int total = 0;
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    total += a[u];
    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        qu.push(v);
      }
    }
  }
  return total;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("test.inp", "r", stdin);
  freopen("testTrau.out", "w", stdout);

  cin >> n >> m >> q;

  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  edges.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].from >> edges[i].to;
    edges[i].from--;
    edges[i].to--;
  }

  queries.resize(q);
  // **Không** đánh dấu deleted khi đang đọc
  for (int i = 0; i < q; i++) {
    auto &qq = queries[i];
    cin >> qq.type;
    cin >> qq.x;
    qq.x--; // dùng cho cả C (node) và D (edge index)
    if (qq.type == 'C') {
      cin >> qq.y;
    } else {
      qq.y = 0; // không dùng
    }
  }

  vector<int> deleted(m, 0);

  // Mô phỏng các truy vấn từ đầu đến cuối (forward)
  for (int i = 0; i < q; i++) {
    char t = queries[i].type;
    int x = queries[i].x;
    int y = queries[i].y;

    if (t == 'C') {
      // thay giá trị khu x thành y
      a[x] = y;
    } else { // 'D'
      // x là chỉ số cạnh (0-based), x nằm trong [0..m-1]
      if (0 <= x && x < m)
        deleted[x] = 1; // xóa cạnh
    }

    // Xây lại đồ thị hiện tại
    vector<vector<int>> adj(n);
    for (int j = 0; j < m; j++) {
      if (!deleted[j]) {
        int u = edges[j].from;
        int v = edges[j].to;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
    }

    // Tính tổng lớn nhất trong các thành phần liên thông
    vector<int> vis(n, 0);
    int best = LLONG_MIN;
    for (int u = 0; u < n; u++) {
      if (!vis[u]) {
        best = max(best, bfs_sum(u, adj, a, vis));
      }
    }

    cout << best << "\n";
  }

  return 0;
}
