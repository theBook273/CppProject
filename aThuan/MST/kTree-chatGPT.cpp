#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

int n, k;
vector<int> adj[MAXN];
bool removed[MAXN]; // đánh dấu đỉnh đã được dùng làm centroid
int subtree[MAXN];  // kích thước mỗi cây con
long long ans = 0;

// --------------------
// 1 Tính kích thước subtree
// --------------------
void dfs_size(int u, int p) {
  subtree[u] = 1;
  for (int v : adj[u])
    if (v != p && !removed[v]) {
      dfs_size(v, u);
      subtree[u] += subtree[v];
    }
}

// --------------------
// 2 Tìm centroid
// --------------------
int find_centroid(int u, int p, int total) {
  for (int v : adj[u])
    if (v != p && !removed[v]) {
      if (subtree[v] * 2 >
          total) // nếu cây con v lớn hơn n/2 → centroid nằm trong đó
        return find_centroid(v, u, total);
    }
  return u; // chính u là centroid
}

// --------------------
// 3 Thu thập độ sâu (khoảng cách) từ centroid tới các node trong 1 subtree
// --------------------
void collect_depth(int u, int p, int depth, vector<int> &depths) {
  if (depth > k)
    return; // không cần đi sâu hơn k
  depths.push_back(depth);
  for (int v : adj[u])
    if (v != p && !removed[v]) {
      collect_depth(v, u, depth + 1, depths);
    }
}

// --------------------
// 4 Đếm các cặp có đường đi qua centroid
// --------------------
void decompose(int u) {
  // Tìm centroid
  dfs_size(u, -1);
  int c = find_centroid(u, -1, subtree[u]);
  removed[c] = true;

  unordered_map<int, int> cnt; // cnt[d] = số node cách c khoảng d
  cnt[0] = 1;                  // bản thân centroid

  // Xử lý từng cây con của centroid
  for (int v : adj[c])
    if (!removed[v]) {
      vector<int> depths;
      collect_depth(v, c, 1, depths);

      // Đếm các cặp giữa subtree hiện tại và các subtree trước đó
      for (int d : depths) {
        if (d <= k)
          ans += cnt[k - d];
      }

      // Cập nhật cnt sau khi đếm xong
      for (int d : depths) {
        if (d <= k)
          cnt[d]++;
      }
    }

  // Đệ quy vào các phần còn lại
  for (int v : adj[c])
    if (!removed[v]) {
      decompose(v);
    }
}

// --------------------
// 5 Main
// --------------------
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  decompose(1);
  cout << ans << "\n";
  return 0;
}
