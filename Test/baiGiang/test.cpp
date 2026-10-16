#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> se;
  int n;
  cin >> n;
  for (int a, i = 0; i < n; i++) {
    cin >> a;
    se.insert(a);
  }
  se.find(5);
}
