#include <bits/stdc++.h>
#include <fstream>
#define int long long

using namespace std;

const int limTest = 1;
const int lim = 20;
const int limNum = 100;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int rad(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  srand(time(0));

  system("g++ 'trau.cpp' -o trau");

  for (int test = 1; test <= limTest; test++) {
    ofstream inp("rating.inp");
    inp << 1 << "\n";
    int n = rad(5, lim);
    int q = rad(1, lim);
    inp << n << " " << q << endl;
    for (int now = 1, i = 0; i < n; i++) {
      now = rad(now, limNum);
      inp << now << " ";
    }
    inp << "\n";
    while (q--) {
      int l = rad(1, n);
      int r = rad(l, n);
      inp << rad(1, limNum) << " " << l << " " << r << endl;
    }
    inp.close();

    system("./trau");
  }
}
