#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));

  system("g++ chuan.cpp -o chuan");
  system("g++ trau.cpp -o trau");

  int limTest = 100;
  int lim = 1e5;
  for (int test = 1; test <= limTest; test++) {
    ofstream inp("test.inp");

    int n = randint(1, lim);
    inp << n << "\n";
    for (int i = 0; i < n; i++) {
      inp << randint(1, 100) << " ";
    }

    inp.close();

    cout << "--- RUNNING ON TEST " << test << " ---\n";
    cout << "RESULT: ";
    system("./chuan");
    system("./trau");

    int check = system("diff chuan.out trau.out");
    if (check) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }

  cout << "ALL TEST PASSED SUCCESSFULL\n";
}
