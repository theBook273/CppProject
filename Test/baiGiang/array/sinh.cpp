#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));
  system("g++ chuan.cpp -o chuan");
  system("g++ trau.cpp -o trau");

  int limTest = 1313;
  int lim = 1000;
  for (int test = 1; test <= limTest; test++) {
    // Generate test file
    ofstream inp("TEST.INP");
    int n = randint(1, lim);
    int k = randint(1, lim);
    inp << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
      if (randint(1, lim) % 5 == 0) {
        inp << k << " ";
        continue;
      }
      inp << randint(1, lim) << " ";
    }
    inp.close();

    // Checker
    cout << "--- RUNNING ON TEST " << test << " ---\n";
    cout << "RESULT: ";
    system("./chuan");
    system("./trau");

    int check = system("diff CHUAN.OUT TRAU.OUT");
    if (check) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }

  cout << "---CONGRATULATION!!!---\n";
  cout << "ALL TEST PASSED SUCCESSFULLY\n\n";
}
