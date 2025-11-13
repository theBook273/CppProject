#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

const char sc[] = {'D', 'C'};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  system("g++ main.cpp -o main");
  system("g++ trau.cpp -o trau");

  for (int test = 1; test <= 10; test++) {
    ofstream inp("test.inp");
    if (!inp.is_open()) {
      cerr << "Cannot open test.inp for writing\n";
      return 0;
    }

    int n = randint(1, 100);
    int m = randint(1, 100);
    int q = randint(1, 100);

    inp << n << " " << m << " " << q << "\n";

    // weights
    for (int i = 0; i < n; i++) {
      inp << randint(1, 100);
      if (i + 1 < n)
        inp << " ";
    }
    inp << "\n";

    // edges (1-based indices in input)
    vector<pair<int, int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++) {
      int u = randint(1, n);
      int v = randint(1, n);
      edges.emplace_back(u, v);
      inp << u << " " << v << "\n";
    }

    // prepare alive list of edge indices (1..m)
    vector<int> alive;
    alive.reserve(m);
    for (int i = 1; i <= m; ++i)
      alive.push_back(i);

    // queries
    for (int i = 0; i < q; i++) {
      // if no alive edges left, force a 'C' query
      bool allowD = !alive.empty();
      char type = sc[randint(0, 1)];
      if (!allowD)
        type = 'C';

      inp << type << " ";
      if (type == 'D') {
        // pick random alive edge index, remove it from alive
        int pos = randint(0, (int)alive.size() - 1);
        int edge_idx = alive[pos]; // 1-based
        // remove by swapping with last for O(1)
        alive[pos] = alive.back();
        alive.pop_back();

        inp << edge_idx << "\n";
      } else {
        int x = randint(1, n);
        int y = randint(1, 1000);
        inp << x << " " << y << "\n";
      }
    }

    inp.close();

    // run programs (both read test.inp via freopen in your codes)
    // programs produce testChuan.out and testTrau.out respectively
    // ensure these executables exist and are runnable
    system("./trau");
    system("./main");

    cout << "---RUNNING TEST " << test << "---\n";
    cout << "RESULT: ";

    // use diff quiet; return code != 0 means difference or error
    int diff_rc = system("diff -q testChuan.out testTrau.out > /dev/null 2>&1");
    if (diff_rc != 0) {
      cout << "WA!!!\n";
      cout << "Bad input (test.inp) saved for inspection.\n";
      // show input briefly
      system("echo '--- test.inp ---'; sed -n '1,200p' test.inp");
      // show diff
      system("echo '--- diff ---'; diff testChuan.out testTrau.out | sed -n "
             "'1,200p'");
      return 0;
    } else {
      cout << "AC\n\n";
    }
  }

  cout << "\nALL AC - NICE!!!\n";
  return 0;
}
