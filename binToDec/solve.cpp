#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    long long n = 0;

    cin >> x;

    for (int i = 1; i <= x.size(); i++) {
        n += ((x[i - 1] - '0') * pow(2, x.size() - i));
    }

    string temp = "";

    stack<int> res;
    int nho = 0;

    while (temp.size() + to_string(n).size() < x.size()) {
        temp += "0";
    }

    temp += to_string(n);

    for (int i = x.size() - 1; i >= 0; i--) {
        int a = x[i] - '0';
        int b = temp[i] - '0';

        if (a + b + nho < 10)
            res.push(a + b + nho), nho = 0;
        else
            res.push((a + b) % 10), nho = 1;
    }

    while (!res.empty()) {
        cout << res.top();
        res.pop();
    }
}