#include <bits/stdc++.h>

using namespace std;

class converter {
private:
  map<string, char> b2h = {
      {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
      {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
      {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
      {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'},
  };
  map<char, string> h2b;

  map<string, char> b2o = {
      {"000", '0'}, {"001", '1'}, {"010", '2'}, {"011", '3'},
      {"100", '4'}, {"101", '5'}, {"110", '6'}, {"111", '7'},
  };
  map<char, string> o2b;

public:
  converter() {
    for (auto [i, j] : b2h) {
      h2b[j] = i;
    }
    for (auto [i, j] : b2o) {
      o2b[j] = i;
    }
  }

  string hex2bin(string input) {
    string res = "";
    string num = input.substr(2);
    for (char i : num) {
      res += h2b[i];
    }
    return res;
  }

  string oct2bin(string input) {
    string res = "";
    string num = input.substr(2);
    for (char i : num) {
      res += o2b[i];
    }
    return res;
  }

  string dec2bin(string input) {
    unsigned long long temp = stoull(input);
    string res;
    while (temp) {
      res += to_string(temp % 2);
      temp /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
  }

  string bin2hex(string input) {
    string res = "";
    while (input.size() % 4 != 0) {
      input = "0" + input;
    }
    for (int i = input.size() - 1; i >= 0; i -= 4) {
      string temp = input.substr(i - 4 + 1, 4);
      res += b2h[temp];
    }
    reverse(res.begin(), res.end());
    return "0x" + res;
  }

  string bin2oct(string input) {
    string res = "";
    while (input.size() % 3 != 0) {
      input = "0" + input;
    }
    for (int i = input.size() - 1; i >= 0; i -= 3) {
      string temp = input.substr(i - 3 + 1, 3);
      res += b2o[temp];
    }
    reverse(res.begin(), res.end());
    return "0o" + res;
  }

  string bin2dec(string input) {
    int res = 0;
    reverse(input.begin(), input.end());
    for (int i = 0; i < input.size(); i++) {
      res += (input[i] - '0') * pow(2, i);
    }
    return to_string(res);
  }

  string convert(int from, int to, string val) {
    switch (from) {
    case 1:
      val = dec2bin(val);
      break;
    case 2:
      val = oct2bin(val);
      break;
    case 4:
      val = hex2bin(val);
      break;
    }

    switch (to) {
    case 1:
      val = bin2dec(val);
      break;
    case 2:
      val = bin2oct(val);
      break;
    case 4:
      val = bin2hex(val);
      break;
    }
    return val;
  }
};
