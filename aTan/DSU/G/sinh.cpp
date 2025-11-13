#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  system("g++ main.cpp -o main");
  system("g++ trau.cpp -o trau");

  int limTest = 555;
  int lim = 273;

  for (int test = 1; test <= limTest; test++) {
    ofstream inp("test.inp");

    int n = randint(1, lim);
    int m = randint(1, lim);
    inp << n << " " << m << "\n";

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        inp << randint(1, lim) << " ";
      }
      inp << "\n";
    }

    int k = randint(1, lim);
    inp << k << "\n";
    for (int i = 0; i < k; i++) {
      inp << randint(1, lim) << "\n";
    }

    inp.close();

    system("./main");
    system("./trau");

    cout << "--- RUNNING TEST: " << test << " ---\n";
    cout << "RESULT: ";
    int check = system("diff testChuan testTrau");
    if (check != 0) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }

  cout << "ALL " << limTest << " TEST AC - NICE!!! \n\n";
}
