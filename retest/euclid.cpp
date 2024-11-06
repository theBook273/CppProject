#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the sum of pairwise distances for a single coordinate
// (x or y)
long long sum_of_distances(const vector<int>& coords, int n) {
    long long total = 0;
    long long prefix_sum = 0;

    for (int i = 0; i < n; ++i) {
        total += 1LL * coords[i] * i - prefix_sum;
        prefix_sum += coords[i];
    }

    return total;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    vector<int> x_coords(n), y_coords(n);

    // Reading points and separating x and y coordinates
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        x_coords[i] = points[i].first;
        y_coords[i] = points[i].second;
    }

    // Sort x and y coordinates
    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());

    // Calculate total distance sum for x and y coordinates separately
    long long total_x = sum_of_distances(x_coords, n);
    long long total_y = sum_of_distances(y_coords, n);

    // Output the final result with precision
    cout.precision(9);
    cout << fixed << (total_x + total_y) << endl;

    return 0;
}
