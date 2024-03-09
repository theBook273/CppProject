#include <bits/stdc++.h>

using namespace std;

class solve {
   public:
    long long longestUp(vector<long long> a) {
        long long tang[a.size()];

        for (int i = 0; i < a.size(); i++) {
            tang[i] = 1;
        }

        for (long long i = 0; i < a.size(); i++) {
            for (long long j = i - 1; j >= 0; j--) {
                if (a[i] > a[j]) {
                    tang[i] = max(tang[i], tang[j] + 1);
                }
            }
        }

        return *max_element(tang, tang + a.size());
    }
};

int main() {
    vector<long long> a;
    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++) {
        long long temp;

        cin >> temp;

        a.push_back(temp);
    }

    solve res;

    cout << res.longestUp(a);
}