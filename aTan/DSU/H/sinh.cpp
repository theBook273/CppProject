#include <bits/stdc++.h>
#include <csignal>
using namespace std;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
char type[] = {'X', '.'};

// Biến toàn cục để biết đang chạy test nào
int currentTest = 0;

void handle_sigint(int) {
  cerr << "\n⚠️  Caught Ctrl+C! Program interrupted at test #" << currentTest
       << ".\n";
  cerr << "👉 Check file 'last_test.txt' for the latest generated test.\n";
  exit(1);
}

signed main() {
  srand(time(0));
  signal(SIGINT, handle_sigint); // Bắt Ctrl+C

  system("g++ main.cpp -o main");
  system("g++ trau.cpp -o trau");

  int limTest = 100;
  int lim = 10;
  int limX = 0;

  for (int test = 1; test <= limTest; test++) {
    currentTest = test; // cập nhật test hiện tại
    ofstream inp("test");
    ofstream backup("last_test.txt"); // lưu backup song song

    int n = randint(1, lim), m = randint(1, lim);
    inp << n << " " << m << "\n";
    backup << n << " " << m << "\n";

    set<pair<int, int>> se;
    while (se.size() < 2) {
      int x = randint(1, n);
      int y = randint(1, m);
      se.insert({x, y});
    }

    int dem = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        if (se.count({i, j}))
          c = 'L';
        else {
          int x = randint(0, 1);
          dem += (x == 1);
          if (dem < limX)
            c = type[x];
          else
            c = 'X';
        }
        inp << c;
        backup << c;
      }
      inp << "\n";
      backup << "\n";
    }

    inp.flush();
    backup.flush();
    inp.close();
    backup.close();

    // Chạy 2 chương trình với timeout để tránh treo
    int ret1 = system("timeout 2s ./main");
    if (ret1 != 0) {
      cout << "main.cpp TIMEOUT or ERROR!\n";
      return 0;
    }

    int ret2 = system("timeout 2s ./trau");
    if (ret2 != 0) {
      cout << "trau.cpp TIMEOUT or ERROR!\n";
      return 0;
    }

    int check = system("diff testTrau testChuan");
    cout << "--- RUNNING ON " << test << " TEST ---\n";
    cout << "RESULT: ";
    if (check) {
      cout << "WA!!!\n";
      cout << "❗ Check 'last_test.txt' to see the failed test.\n\n";
      return 0;
    }
    cout << "AC\n\n";
  }

  cout << "ALL " << limTest << " TEST AC - NICE!!! 🎉\n\n";
}
