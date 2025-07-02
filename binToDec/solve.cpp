#include <bits/stdc++.h>

using namespace std;

long long main() {
    string x;
    long long n = 0;

    cin >> x;

    for (long long i = 1; i <= x.size(); i++) {
        n += ((x[i - 1] - '0') * pow(2, x.size() - i));
    }

    string temp = "";

    stack<long long> res;
    long long nho = 0;

    while (temp.size() + to_string(n).size() < x.size()) {
        temp += "0";
    }

    temp += to_string(n);

    for (long long i = x.size() - 1; i >= 0; i--) {
        long long a = x[i] - '0';
        long long b = temp[i] - '0';

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
