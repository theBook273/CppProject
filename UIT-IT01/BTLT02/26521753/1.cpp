#include <bits/stdc++.h>

using namespace std;

signed main() {
  double a, b, c;
  cout << "======= Tim so lon nhat/ nho nhat trong 3 so =======\n";
  cout << "\n===================== INPUT ========================\n";
  cout << "nhap vao so a: ";
  cin >> a;
  cout << "nhap vao so b: ";
  cin >> b;
  cout << "nhap vao so c: ";
  cin >> c;
  cout << "\n===================== OUTPUT =======================\n";
  cout << "So lon nhat trong 3 so: ";
  cout << max(a, max(b, c)) << "\n";
  cout << "So nho nhat trong 3 so: ";
  cout << min(a, min(b, c)) << "\n";
}
