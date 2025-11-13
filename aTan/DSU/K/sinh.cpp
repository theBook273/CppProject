#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

struct War {
  int l, r, win;
};

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));

  system("g++ main.cpp -o main");
  system("g++ trau.cpp -o trau");

  int limTest = 555;
  int lim = 1000;
  for (int test = 1; test <= limTest; test++) {
    ofstream inp("test");

    int n = randint(1, lim);
    int m = randint(1, n);
    vector<bool> alive(n + 1, 1);
    vector<War> war;

    for (int i = 0; i < m; i++) {
      int l = randint(1, n);
      int r = randint(l, n);

      vector<int> warrior;
      for (int j = l; j <= r; j++) {
        if (alive[j]) {
          warrior.push_back(j);
        }
      }

      if (warrior.empty()) {
        continue;
      }

      int win = warrior[randint(0, warrior.size() - 1)];
      war.push_back({l, r, win});

      for (int j = l; j <= r; j++) {
        if (j != win) {
          alive[j] = 0;
        }
      }
    }

    inp << n << " " << war.size() << "\n";
    for (auto [l, r, win] : war) {
      inp << l << " " << r << " " << win << "\n";
    }
    inp.close();

    cout << "--- RUNNING ON TEST: " << test << " ---\n";
    cout << "RESULT: ";
    bool tle = system("timeout 2s ./main");
    if (tle) {
      cout << "MAIN TIMEOUT\n\n";
    }

    tle = system("timeout 2s ./trau");
    if (tle) {
      cout << "TRAU TIMEOUT\n\n";
    }

    int check = system("diff testTrau testChuan");
    if (check) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }
  cout << "--- ALL TEST PASSED SUCCESSFULLY ---\n\n";
}
