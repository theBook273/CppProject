// PFR solution - functional graph
// Compile: g++ -O2 -std=c++17 pfr.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  if (!(cin >> n))
    return 0;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i]; // zero-based
  }

  // 1) find cycles and cycle lengths
  vector<int> state(n, 0); // 0 = unvisited, 1 = in current stack, 2 = done
  vector<int> in_cycle(n, 0);
  vector<int> cycle_lengths;
  vector<int> pos(n, -1);

  for (int i = 0; i < n; ++i) {
    if (state[i] != 0)
      continue;
    vector<int> path;
    int u = i;
    while (state[u] == 0) {
      state[u] = 1;
      pos[u] = (int)path.size();
      path.push_back(u);
      u = p[u];
    }
    if (state[u] == 1) {
      // found a cycle: nodes from pos[u] .. end of path
      int start = pos[u];
      int len = (int)path.size() - start;
      cycle_lengths.push_back(len);
      for (int k = start; k < (int)path.size(); ++k)
        in_cycle[path[k]] = 1;
    }
    // mark whole path as done and reset pos
    for (int v : path) {
      state[v] = 2;
      pos[v] = -1;
    }
  }

  // 2) build reverse graph and BFS from cycle nodes to get depths
  vector<vector<int>> rev(n);
  for (int i = 0; i < n; ++i)
    rev[p[i]].push_back(i);

  vector<int> dist(n, -1);
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (in_cycle[i]) {
      dist[i] = 0;
      q.push(i);
    }
  }
  int max_depth = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : rev[u]) {
      if (in_cycle[v])
        continue; // don't re-enter cycle nodes
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        max_depth = max(max_depth, dist[v]);
        q.push(v);
      }
    }
  }

  // 3) compute L = lcm of cycle_lengths via prime factorization using SPF
  int maxLen = 0;
  for (int c : cycle_lengths)
    if (c > maxLen)
      maxLen = c;
  if (maxLen < 2)
    maxLen = 2; // ensure sieve size >= 2
  int S = maxLen;
  vector<int> spf(S + 1);
  for (int i = 2; i <= S; ++i) {
    if (!spf[i]) {
      for (int j = i; j <= S; j += i)
        if (!spf[j])
          spf[j] = i;
    }
  }

  unordered_map<int, int> bestExp; // prime -> max exponent
  for (int c : cycle_lengths) {
    int x = c;
    while (x > 1) {
      int pr = spf[x];
      int e = 0;
      while (x % pr == 0) {
        x /= pr;
        ++e;
      }
      if (bestExp.find(pr) == bestExp.end() || bestExp[pr] < e)
        bestExp[pr] = e;
    }
  }

  // compute L mod MOD
  ll Lmod = 1;
  for (auto &pe : bestExp) {
    int pr = pe.first;
    int e = pe.second;
    // fast pow
    ll base = pr;
    ll res = 1;
    ll pw = base % MOD;
    int exp = e;
    while (exp) {
      if (exp & 1)
        res = (res * pw) % MOD;
      pw = (pw * pw) % MOD;
      exp >>= 1;
    }
    Lmod = (Lmod * res) % MOD;
  }

  // answer = max_depth + Lmod (mod MOD)
  ll ans = ((ll)max_depth + Lmod) % MOD;
  cout << ans << '\n';
  return 0;
}
