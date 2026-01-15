#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(nullptr));

  system("g++ SORT.cpp -o SORT");

  int limTest = 1;
  int limN = 100;
  int limA = 1e3;

  for (int test = 1; test <= limTest; test++) {
    ofstream inp("SORT.INP");

    int n = rd(limN, limN);
    inp << n << "\n";

    for (int i = 1; i <= n; i++) {
      int temp = 1;
      temp = rd(temp, limA);
      if (100 <= i && i <= 10000) {
        inp << i << " ";

      } else
        inp << temp << " ";
    }

    inp.close();

    system("./SORT");
  }
}
