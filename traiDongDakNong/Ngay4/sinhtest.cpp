#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randInt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
const char type[] = {'(', ')', '[', ']', '{', '}', '?'};

signed main() {
  cin.tie()->sync_with_stdio(0);
  srand(time(0));

  for (int test = 1; test <= 1; test++) {
    ofstream inp("test.inp");

    inp << "{?()?}";

    system("./FBRA");
    system("./FBRA-suytOP");

    if (system("diff testChuan.out testTrau.out") != 0) {
      cout << "Test: " << test << ": WA\n";
      return 0;
    }

    cout << "Test: " << test << ": AC\n";
  }
}
