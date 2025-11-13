#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randInt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

const int MINN = 1, MAXN = 10;
const int MINM = 1, MAXM = 10;
const int MINV = 1, MAXV = 10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int test = 1; test <= 100; test++) {
    ofstream inp("test.inp");

    int n = randInt(MINN, MAXN);
    int m = randInt(MINM, MAXM);

    inp << n << " " << m << "\n";

    // Sinh n cặp giá trị
    for (int i = 1; i <= n; i++) {
      inp << randInt(MINV, MAXV) << " " << randInt(MINV, MAXV) << " ";
    }
    inp << "\n";

    // Sinh m truy vấn
    for (int i = 1; i <= m; i++) {
      int tp = randInt(1, 6);
      int l = randInt(1, n);
      int h = randInt(1, n);
      if (l > h)
        swap(l, h);
      int v = randInt(MINV, MAXV);

      if (tp <= 4)
        inp << tp << " " << l << " " << h << " " << v << "\n";
      else
        inp << tp << " " << l << " " << h << "\n";
    }

    // Sinh 2 giá trị cuối
    inp << randInt(MINV, MAXV) << " " << randInt(MINV, MAXV);
    inp.close();

    // Chạy chương trình và so sánh output
    system("./trau");
    system("./chuan");

    if (system("diff testChuan.out testTrau.out") != 0) {
      cout << "Test " << test << ": WRONG!\n";
      return 0;
    }

    cout << "Test " << test << ": CORRECT!\n";
  }

  return 0;
}
