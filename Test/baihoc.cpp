// C++Project/Test/baihoc.cpp
// Simple binary search program
// Reads n, then n integers (assumed sorted ascending), then a target value from keyboard
// Prints the found index (0-based and 1-based) or "Not found".

#include <bits/stdc++.h>
using namespace std;

int binary_search_idx(const vector<long long>& a, long long x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements (n): ";
    if (!(cin >> n)) {
        cerr << "Invalid input for n\n";
        return 1;
    }
    if (n <= 0) {
        cerr << "n must be positive\n";
        return 1;
    }

    vector<long long> a(n);
    cout << "Enter " << n << " integers (sorted in ascending order):\n";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) {
            cerr << "Invalid input at element " << i << "\n";
            return 1;
        }
    }

    long long target;
    cout << "Enter target value: ";
    if (!(cin >> target)) {
        cerr << "Invalid input for target\n";
        return 1;
    }

    int idx = binary_search_idx(a, target);
    if (idx != -1) {
        cout << "Found at index (0-based): " << idx
             << "  (1-based): " << (idx + 1) << "\n";
    } else {
        cout << "Not found\n";
    }

    return 0;
}
