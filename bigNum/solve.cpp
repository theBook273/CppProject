#include <bits/stdc++.h>

using namespace std;

// string sub(string s) {
//     reverse(s.begin(), s.end());
//     string temp = "1";
//     while (temp.size() < s.size()) {
//         temp += "0";
//     }

//     string res;

//     long long nho = 0;
//     for (long long i = 0; i < s.size(); ++i) {
//         if ((s[i] - '0') - (temp[i] - '0') - nho >= 0) {
//             res += ((s[i] - '0') - (temp[i] - '0') - nho) + '0';
//             nho = 0;
//         } else {
//             res += (10 + (s[i] - '0') - (temp[i] - '0') - nho) + '0';
//             nho = 1;
//         }
//     }

//     if (res[res.size() - 1] == '0' && res.size() > 1) res.pop_back();
//     reverse(res.begin(), res.end());

//     return res;
// }

string mul(string a, string b) {
    string res(a.size() + b.size(), '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (long long i = 0; i < a.size(); ++i) {
        long long nho = 0, j;
        for (j = 0; j < b.size(); ++j) {
            long long x = (a[i] - '0') * (b[j] - '0') + nho + (res[i + j] - '0');
            res[i + j] = x % 10 + '0';
            nho = x / 10;
        }
        if (nho > 0) res[i + j] = nho + '0';
    }

    if (res[res.size() - 1] == '0' && res.size() > 1) res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

main() {
    long long n;
    cin >> n;

    string a = "1";

    for (long long i = 1; i <= n; i++) {
        a = mul(a, to_string(i));
    }
    cout << a << endl;
}
