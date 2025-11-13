#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));

  system("g++ main.cpp -o main");
  system("g++ trau.cpp -o trau");

  int limTest = 555;
  int lim = 4000;

  for (int test = 1; test <= limTest; test++) {
    ofstream inp("test");

    int n = randint(1, lim);
    inp << n << "\n";

    for (int i = 0; i < n; i++) {
      inp << randint(1, lim) << " ";
    }

    inp.close();

    cout << "--- RUNNING ON TEST " << test << " ---\n";
    cout << "RESULT: ";

    bool tle = system("timeout 2s ./main");
    if (tle) {
      cout << "MAIN TIMEOUT\n\n";
      return 0;
    }

    tle = system("timeout 2s ./trau");
    if (tle) {
      cout << "TRAU TIMEOUT\n\n";
      return 0;
    }

    int check = system("diff testTrau testChuan");
    if (check) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }
  cout << "ALL " << limTest << " TEST(S) AC - NICE!!!!!\n\n";
}
