#include <bits/stdc++.h>

using namespace std;

const double ESP = 1e-12;

signed main() {
  double a, b, c;
  cout << "======= Kiem tra tam giac =======\n";
  cout << "\n============ INPUT ==============\n";
  cout << "nhap vao canh a: ";
  cin >> a;
  cout << "nhap vao canh b: ";
  cin >> b;
  cout << "nhap vao canh c: ";
  cin >> c;
  cout << "\n============ OUTPUT =============\n";
  if ((a + b) - c > ESP && (a + c) - b > ESP && (b + c) - a > ESP) {
    cout << "Day la mot tam giac\n";
  } else {
    cout << "Day khong phai la mot tam giac\n";
  }
}
