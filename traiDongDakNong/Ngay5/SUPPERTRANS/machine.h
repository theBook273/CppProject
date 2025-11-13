#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Captain {
private:
  void process(string &s, int &x) {
    bitset<17> a(x);
    for (int i = 16; i >= 0; i--) {
      if (a[i] == 1) {
        s += "1";
      } else {
        s += "0";
      }
    }
  }

  void toBin17(string &time, string &encoded) {
    int h;
    h = time[0] - '0';
    h = h * 10 + (time[1] - '0');

    int m;
    m = time[3] - '0';
    m = m * 10 + (time[4] - '0');

    int s;
    s = time[6] - '0';
    s = s * 10 + (time[7] - '0');

    int num = h * 3600 + m * 60 + s;

    process(encoded, num);
  }

  void toBin5(int &s, string &encoded) {
    bitset<5> a(s);
    for (int i = 4; i >= 0; i--) {
      encoded += (a[i] == 1 ? "1" : "0");
    }
  }

  void parityEncrypt(string &s) {
    int dem = 0;
    for (auto &i : s) {
      dem += (i == '1');
    }
    s += to_string((dem % 2));
  }

  void VTencrypt(string &s) {
    int dem = 0;
    for (int i = 1; i <= 17; i++) {
      dem += (i * (s[i - 1] - '0'));
    }

    dem = dem % 18;

    toBin5(dem, s);
  }

public:
  Captain() {}

  string encode(string time) {
    string encoded;

    toBin17(time, encoded);
    parityEncrypt(encoded);
    VTencrypt(encoded);

    return encoded;
  }
};

//==========================================================================//
class Soldier {
private:
  int id;

  int binToDec(const string &s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[s.size() - 1 - i] == '1') {
        res |= (1 << i);
      }
    }
    return res;
  }

  int calParity(string &s) {
    int temp = 0;
    for (int i = 0; i < 17; i++) {
      temp += (s[i] == '1');
    }
    return (temp % 2);
  }

  int calVT(string &s) {
    int temp = 0;
    for (int i = 0; i < 17; i++) {
      temp += ((s[i] - '0') * (i + 1));
    }
    return temp % 18;
  }

  void parityCorrect(string &s) {
    int dem = 0;
    for (int i = 0; i < 17; i++) {
      dem += (s[i] - '0');
    }

    if (dem % 2 != (s[17] - '0')) {
      string VT;

      for (int i = 18; i < s.size(); i++) {
        VT.push_back(s[i]);
      }

      int received = binToDec(VT);

      if (calVT(s) == received) {
        return;
      }

      for (int pos = 0; pos < 17; pos++) {
        string temp = s;
        temp[pos] = (temp[pos] == '0' ? '1' : '0');
        if (calParity(temp) == (s[17] - '0') && calVT(temp) == received) {
          s = temp;
          return;
        }
      }
    }
  }

  void format(string &s, int a) {
    if (a < 10) {
      s += "0";
    }
    s += to_string(a);
  }

  string decodeX(string &s) {
    string temp;
    int res = 0;

    for (int i = 0; i < 17; i++) {
      temp.push_back(s[i]);
    }

    res = binToDec(temp);

    int se = res % 60;
    res /= 60;
    int mi = res % 60;
    int h = res / 60;

    string secs, mins, hours;
    format(secs, se);
    format(mins, mi);
    format(hours, h);

    return hours + ":" + mins + ":" + secs;
  }

public:
  Soldier(int id) : id(id) {}
  string decode(string s) {
    if (s.size() == 23) {
      parityCorrect(s);
    }

    return decodeX(s);
  }
};

// #include "main.h"
