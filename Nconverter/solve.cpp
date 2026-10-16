#include "convert.h"
#include <bits/stdc++.h>

using namespace std;
int from, to;
string val;

signed main() {
  ios::sync_with_stdio(0);

  cout << "Number system converter\n";
  cout << "=======================\n";
  cout << "1. Dec\n";
  cout << "2. Oct\n";
  cout << "3. Bin\n";
  cout << "4. Hex\n";
  cout << "=======================\n";
  cout << "Choose system to convert from: ";
  cin >> from;
  cout << "=======================\n";
  cout << "Choose system to convert to: ";
  cin >> to;
  cout << "=======================\n";
  cout << "Value: ";
  cin >> val;

  converter temp;
  cout << "Converted number: " << temp.convert(from, to, val) << "\n";
}
