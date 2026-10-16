#include <bits/stdc++.h>

int diff(int a, int b) {
  while (a != b) {
    if (a < b) {
      std::swap(a, b);
    }
    a -= b;
  }
  return a;
}

int eu(int a, int b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

signed main() { std::cout << eu(16, 40); }
