#include <bits/stdc++.h>
#define int long long

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));
  system("g++ main.cpp -o main");
  system("g++ trau.cpp -o trau");

  int limTest = 555;
  int lim = 500;
  for (int test = 1; test <= limTest; test++) {
    ofstream inp("test");

    int n = randint(2, lim);
    int m = randint(n, lim);
    inp << n << " " << m << "\n";

    for (int i = 0; i < m; i++) {
      int u = randint(1, n);
      int v = randint(1, n);
      while (v == u) {
        v = randint(1, n);
      }
      int w = randint(1, lim);
      inp << u << " " << v << " " << w << "\n";
    }
    inp.close();

    cout << "--- RUNNING ON TEST " << test << " ---\n";
    cout << "RESULT: ";

    bool tle = system("timeout 1s ./main");
    if (tle) {
      cout << "MAIN TIMEOUT/ERROR\n\n";
      return 0;
    }

    tle = system("timeout 2s ./trau");
    if (tle) {
      cout << "TRAU TIMEOUT/ERROR\n\n";
      return 0;
    }

    int check = system("diff testChuan testTrau");
    if (check) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }
  cout << "ALL TEST PASSED SUCCESSFULLY\n";
}
