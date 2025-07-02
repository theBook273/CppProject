#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc để lưu đoạn số may mắn
struct Interval {
    long long start, end;
};

// Hàm so sánh để sắp xếp các đoạn theo điểm kết thúc tăng dần
bool compare(const Interval &a, const Interval &b) { return a.end < b.end; }

long long main() {
    long long N, K;
    cin >> N >> K;

    vector<Interval> long longervals(K);
    for (long long i = 0; i < K; i++) {
        cin >> long longervals[i].start >> long longervals[i].end;
    }

    // Sắp xếp các đoạn theo điểm kết thúc
    sort(long longervals.begin(), long longervals.end(), compare);

    long long count = 0;  // Đếm số bạn tối đa có thể trúng lì xì
    long long last_chosen = -1;  // Số cuối cùng đã chọn trước đó (ban đầu đặt là -1
                           // để không chồng chéo)

    for (const auto &long longerval : long longervals) {
        // Nếu đoạn này không chồng chéo với số đã chọn trước đó
        if (long longerval.start > last_chosen) {
            last_chosen = long longerval.end;  // Chọn số cuối của đoạn
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
