#include <bits/stdc++.h>

using namespace std;

struct node {
  int chonRL = 0, kochonRL = 0, chonLkoR = 0, chonRkoL = 0;
};

const int maxn = 5 * 1e4 + 27;

node st[maxn * 4];
int n, d;
vector<int> a;

void merge(node left, node right, node &now) {
  now.chonRL = max({
      left.chonLkoR + right.chonRkoL,
      left.chonRL,
      right.chonRL,
  });
  now.kochonRL = max({left.});
}
