#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc để lưu đoạn số may mắn
struct Interval {
    int start, end;
};

// Hàm so sánh để sắp xếp các đoạn theo điểm kết thúc tăng dần
bool compare(const Interval &a, const Interval &b) { return a.end < b.end; }

int main() {
    int N, K;
    cin >> N >> K;

    vector<Interval> intervals(K);
    for (int i = 0; i < K; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    // Sắp xếp các đoạn theo điểm kết thúc
    sort(intervals.begin(), intervals.end(), compare);

    int count = 0;  // Đếm số bạn tối đa có thể trúng lì xì
    int last_chosen = -1;  // Số cuối cùng đã chọn trước đó (ban đầu đặt là -1
                           // để không chồng chéo)

    for (const auto &interval : intervals) {
        // Nếu đoạn này không chồng chéo với số đã chọn trước đó
        if (interval.start > last_chosen) {
            last_chosen = interval.end;  // Chọn số cuối của đoạn
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
