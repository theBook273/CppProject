#include <iostream>
using namespace std;

long long countOnes(long long n) {
    long long result = 0;
    long long k = 0;
    while ((1LL << k) <= n) {
        long long cycle = 1LL << (k + 1);
        long long fullCycles = (n + 1) / cycle;
        long long count = fullCycles * (1LL << k);
        long long remainder = (n + 1) % cycle;
        count += max(0LL, remainder - (1LL << k));
        result += count;
        k++;
    }
    return result;
}

long long main() {
    long long n;
    cin >> n;
    cout << countOnes(n) << endl;
    return 0;
}
