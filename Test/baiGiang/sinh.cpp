#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));

  system("g++ solve.cpp -o solve");
  system("g++ test.cpp -o test");

  int limTest = 100;
  int lim = 100000;
  for (int test = 1; test <= limTest; test++) {
    ofstream inp("TEST.INP");

    int t = randint(1, 9261);
    inp << t << endl;
    while (t--) {
      int a = randint(0, 20);
      int b = randint(0, 20);
      int c = randint(0, 20);
      if (randint(1, lim) % 2 == 0) {
        inp << a << " " << b << " " << a + b << endl;
      } else
        inp << a << " " << b << " " << c << endl;
    }

    inp.close();

    cout << "--- RUNNING ON TEST " << test << " ---\n";
    cout << "RESULT: ";
    system("./solve");
    system("./test");

    int check = system("diff TEST.OUT SOLVE.OUT");
    if (check) {
      cout << "WA on Test" << test << "\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }

  cout << "ALL TEST PASSED SUCCESSFULL\n";
}
