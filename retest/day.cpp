#include <iostream>
using namespace std;

// A helper function to calculate long longeger powers (base^exp)
unsigned long long long longPow(unsigned long long base, unsigned long long exp) {
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

long long main() {
    unsigned long long k;
    cin >> k;

    while (k--) {
        unsigned long long n;
        cin >> n;

        unsigned long long digit = 1, base = 9;

        // Finding the range where the nth digit lies
        while (n > base * digit) {
            n -= base * digit;
            digit++;
            base *= 10;
        }

        // Finding the exact number and digit position
        unsigned long long num = long longPow(10, digit - 1) + (n - 1) / digit;
        unsigned long long r = (n - 1) % digit;

        // Converting number to string to easily access digits
        string numStr = to_string(num);

        // Output the corresponding digit
        cout << numStr[r] << endl;
    }

    return 0;
}
