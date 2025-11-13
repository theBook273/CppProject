#include <algorithm>
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007;
const int MAXN = 1e5;

vector<int> adj, rev[MAXN + 5], dis, depth;
vector<vector<int>> cycle;
int n, timer, L = 0;

void createCycle() {
  vector<int> backTrack, vis(n + 1, 0);
  timer = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      backTrack.clear();
      timer++;
      int now = i;
      while (true) {
        vis[now] = 1;
        backTrack.push_back(now);

        int nxt = adj[now];

        if (vis[nxt] == 1) {
          vector<int> cyc;
          for (int x : backTrack) {
            if (x == nxt) {
              cyc.clear();
            }
            cyc.push_back(x);
          }

          cycle.push_back(cyc);
          for (int x : cyc) {
            vis[x] = 2;
          }
          break;
        }

        if (vis[nxt] == 2) {
          break;
        }

        now = nxt;
      }

      for (int x : backTrack) {
        if (vis[x] != 2) {
          vis[x] = 2;
        }
      }
    }
  }
}

void bfs(int now) {
  queue<int> q;
  for (auto x : cycle[now]) {
    q.push(x);
    dis[x] = 0;
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : rev[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        depth[now] = max(depth[now], dis[v]);
        q.push(v);
      }
    }
  }
}

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

int binPow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int calcRes() {
  if (cycle.size() == 1) {
    return cycle[0].size();
  }

  int maxLen = 0, res = 1;
  for (auto i : cycle) {
    maxLen = max(maxLen, (int)i.size());
  }

  vector<int> prime(maxLen + 1, 1), best(maxLen + 1, 0);
  for (int i = 0; i <= maxLen; i++) {
    prime[i] = i;
  }

  for (int i = 2; i <= maxLen; i++) {
    if (prime[i] == i) {
      prime[i] = i;
      for (int j = i; j <= maxLen; j += i) {
        prime[j] = min(prime[j], i);
      }
    }
  }

  for (auto i : cycle) {
    int x = i.size();
    while (x > 1) {
      int p = prime[x];
      int cnt = 0;
      while (prime[x] == p) {
        x /= p, cnt++;
      }
      best[p] = max(best[p], cnt);
    }
  }

  for (int i = 2; i <= maxLen; i++) {
    res = mul(res, binPow(i, best[i]));
    res %= MOD;
  }

  return res % MOD;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  adj.resize(n + 1);
  dis.resize(n + 1, 1e9);
  for (int i = 1; i <= n; i++) {
    cin >> adj[i];
  }

  createCycle();

  for (int i = 1; i <= n; i++) {
    rev[adj[i]].push_back(i);
  }

  depth.resize(timer + 1, 0);

  for (int i = 0; i < cycle.size(); i++) {
    bfs(i);
    L = max(L, depth[i]);
  }

  int res = calcRes();
  cout << (res % MOD + L % MOD) % MOD;
}
