#include <bits/stdc++.h>
#include <cstdlib>
#include <fstream>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));

  system("g++ solve.cpp -o solve");
  system("g++ trau.cpp -o trau");

  int limTest = 10;
  int lim = 100000;
  for (int test = 1; test <= limTest; test++) {
    ofstream inp("FOURDIV.INP");
    inp << randint(1, lim);
    inp.close();

    cout << "--- RUNNING ON TEST " << test << " ---\n";
    cout << "RESULT: ";
    system("./trau");
    system("./solve");

    int check = system("diff FOURDIVTRAU.OUT FOURDIV.OUT");
    if (check) {
      cout << "WA!!!\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }

  cout << "ALL TEST PASSED SUCCESSFULL\n";
}
