#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));
  system("g++ main.cpp -o main");
  system("g++ trau.cpp -o trau");

  int limTest = 555;
  int cntTest = 10;
  for (int test = 1; test <= limTest; test++) {
    ofstream inp("test");
    for (int i = 1; i <= cntTest; i++) {
      int n = randint(1, 50);
      set<pair<int, int>> se;
      while (se.size() < n) {
        int x = randint(1, 100);
        int y = randint(1, 100);
        se.insert({x, y});
      }

      inp << n << "\n";
      for (auto [x, y] : se) {
        inp << x << " " << y << "\n";
      }
    }
    inp << 0 << "\n";
    inp.close();

    system("./main");
    system("./trau");

    int check = system("diff testTrau testChuan");

    cout << "--- RUNNING TEST " << test << " ---\n";
    cout << "RESULT: ";
    if (check != 0) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }
  cout << "ALL " << limTest << " TEST(S) AC - NICE!!!\n";
}
