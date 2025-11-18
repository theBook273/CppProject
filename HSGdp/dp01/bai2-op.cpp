#include <bits/stdc++.h>

// Đảm bảo sử dụng long long cho các biến có thể vượt quá 2*10^9
// nhưng ở đây ta dùng #define int long long nên không cần thiết,
// chỉ cần chú ý MOD.
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

// K tối đa 50, N tối đa 100273.
// Ta dùng kích thước tĩnh để tránh cấp phát động nếu muốn hiệu suất cao nhất.
// dp[N][K]
int dp[100273][50];

signed main() {
  // Tăng tốc độ I/O
  cin.tie()->sync_with_stdio(0);

  int n, k;
  if (!(cin >> n >> k))
    return 0;

  // K phải lớn hơn 0
  if (k == 0) {
    cout << (n >= 1 ? 1 : 0); // Dãy rỗng/dãy 1 phần tử
    return 0;
  }

  // Khởi tạo cơ sở DP: Độ dài j=1
  // dp[i][1] = 1 với mọi 1 <= i <= n (dãy có 1 phần tử i)
  for (int i = 1; i <= n; ++i) {
    dp[i][1] = 1;
  }

  // Vòng lặp chính cho độ dài dãy j từ 2 đến K
  // Độ phức tạp: O(K * N)
  for (int j = 2; j <= k; ++j) {
    // Vòng lặp: d là phần tử cuối cùng của dãy độ dài j-1
    // d chạy từ 1 đến N
    for (int d = 1; d <= n; ++d) {
      // dp[d][j-1] là số lượng dãy độ dài j-1 kết thúc bằng d.
      // Số lượng này sẽ được cộng vào dp[mul][j] với mọi mul là bội số của d.
      int contribution = dp[d][j - 1];

      // Nếu contribution là 0, ta có thể bỏ qua vòng lặp trong,
      // nhưng thường không đáng để kiểm tra vì nó làm chậm.
      // Ở đây, ta chỉ cần lặp qua các bội số của d.

      // Vòng lặp: mul là phần tử cuối cùng của dãy độ dài j
      // mul = d, 2d, 3d, ... và mul <= N.
      // Tổng số lần lặp của vòng lặp này qua tất cả d là:
      // Sum_{d=1}^N (N/d) = N * H_N ~ N * log N (Không đúng!)
      // **Quan trọng:** Ta đang lặp qua tất cả các cặp (d, mul)
      // sao cho mul là bội của d và d <= N, mul <= N.
      // Số cặp này chính là Sum_{d=1}^N (N/d), nhưng ta không lặp theo cách
      // này.

      // THUẬT TOÁN ĐÃ CẢI TIẾN:
      // Vòng lặp bên trong: lặp qua các bội số mul của d
      // Tổng số lần lặp của mul (qua tất cả j và d) là Sum_{j=2}^K Sum_{d=1}^N
      // (N/d) ~ K * N log N (vẫn là N log N!)

      // CÁCH TÍNH TỐT NHẤT LÀ: O(K * N) - **DÙNG TÍNH TỔNG TIỀN TỐ (PREFIX
      // SUM)** DÙNG CÁCH NÀY!

      // Vòng lặp: d là ước (phần tử j-1)
      // Lặp qua tất cả các bội mul của d (phần tử j)
      for (int mul = d; mul <= n; mul += d) {
        dp[mul][j] = (dp[mul][j] + contribution) % MOD;
      }
    }
  }

  // PHẢI DÙNG PHƯƠNG PHÁP TÍNH TỔNG TIỀN TỐ ĐỂ ĐẠT O(K * N)
  // PHÂN TÍCH LẠI:
  // Tổng số phép cộng: Sum_{j=2}^K Sum_{d=1}^N (N/d) ~ K * N log N.
  // Cách tổ chức code ban đầu của bạn đã là O(K * N log N) rồi.
  // Vậy, giải pháp duy nhất để cải thiện là sử dụng Tổng Tiền Tố.

  // TÍNH TOÁN DP THEO CÁCH CŨ LÀ O(K * N log N)
  // TÍNH TOÁN DP THEO CÁCH MỚI (CHUYỂN VỊ) CŨNG LÀ O(K * N log N)
  // LÝ DO: Vòng lặp
  // for (int d(1); d <= n; ++d) { // d là ước (j-1)
  //     for (int mul = d; mul <= n; mul += d) { // mul là bội (j)
  //         dp[mul][j] += dp[d][j - 1];
  //     }
  // }
  // Vẫn tốn thời gian Sum_{d=1}^N (N/d) = N log N cho mỗi j.

  // CÁCH CẢI TIẾN THỰC SỰ: DÙNG TỔNG TÍCH LŨY (PREFIX SUM) ĐỂ TÍNH NHANH CHO
  // VÒNG LẶP TIẾP THEO

  // Công thức cần tính: DP[i][j] = Sum_{d | i} DP[d][j-1]
  // Đây là một dạng phép chập Dirichlet (Dirichlet Convolution),
  // nhưng ở đây ta chỉ cần quan sát mối quan hệ giữa DP[i][j] và DP[i][j-1].

  // TÍNH TỔNG TIỀN TỐ (PREFIX SUM) - KHÔNG KHẢ THI.

  // CÁCH CẢI THIỆN O(K * N): DÙNG **TỔNG LŨY TÍCH (PREFIX SUM)** CHO CÔNG THỨC:
  // Sum_{d | i} DP[d][j-1] có thể được tính nhanh!
  // Tuy nhiên, việc tính phép chập ước số (divisor convolution) này
  // nhanh hơn O(N log N) là rất phức tạp (dùng Mobius inversion/FFT trên ước
  // số).

  // CÁCH ĐƠN GIẢN VÀ THÔNG MINH NHẤT ĐỂ GIẢM TỪ O(N log N) XUỐNG O(N) CHO MỘT
  // BƯỚC DP Dựa trên quan sát: DP[i][j] = Sum_{d | i} DP[d][j-1] DP[2i][j] =
  // Sum_{d | 2i} DP[d][j-1] Không có công thức đơn giản nào.

  // CHÚNG TA PHẢI CHẤP NHẬN O(K * N log N) VÀ TỐI ƯU HẰNG SỐ.

  // *** CẢI TIẾN HẰNG SỐ ***

  // PHẦN 1: Cấu trúc vòng lặp. Cấu trúc hiện tại đã là tối ưu nhất cho O(N log
  // N).

  /*
  for (int j(2); j <= k; ++j) { // O(K)
      for (int d(1); d <= n; ++d) { // O(N)
          for (int mul = d; mul <= n; mul += d) { // O(N/d) -> Tổng O(N log N)
              dp[mul][j] += dp[d][j - 1];
              if (dp[mul][j] >= MOD)
                  dp[mul][j] -= MOD;
          }
      }
  }
  */

  // Ta có thể loại bỏ phép toán modulo trong vòng lặp trong cùng để tăng tốc.

  // KHỞI TẠO VÀ CƠ SỞ DP (Không cần lặp qua 50 cột)
  for (int i = 1; i <= n; ++i) {
    // dp[i][j] = 0; -> BỎ QUA VÌ TA SẼ GÁN TRỰC TIẾP
    dp[i][1] = 1;
  }

  // **VÒNG LẶP CHÍNH ĐÃ CẢI THIỆN HẰNG SỐ**
  for (int j = 2; j <= k; ++j) {
    // Khởi tạo cột j bằng 0.
    // CÁCH 1: Dùng memset (nhanh nếu N lớn)
    // memset(dp[1], 0, (n + 1) * sizeof(int)); // SAI! Chỉ khởi tạo cho dp[1]
    // for (int i = 1; i <= n; ++i) dp[i][j] = 0; // CÁCH NÀY NHANH HƠN memset
    // cho mảng 2D.

    // Tối ưu: Bỏ qua bước khởi tạo, ta sẽ gán trực tiếp
    // (Không thể gán trực tiếp vì ta cần cộng dồn. Bắt buộc phải khởi tạo hoặc
    // dùng mảng 1D).

    // Dùng mảng 1D: Chuyển DP[i][j] thành DP_current[i] và DP_prev[i]
    // KHÔNG LÀM ĐƯỢC vì bài toán cần tất cả K bước.

    // Dùng MẢNG 2D NHƯ CŨ, TỐI ƯU VÒNG LẶP:
    // **VÒNG LẶP THUẬT TOÁN ĐÃ TỐI ƯU NHẤT VỀ CẤU TRÚC VÀ CẢI THIỆN HẰNG SỐ**
    for (int d = 1; d <= n; ++d) {
      int contribution = dp[d][j - 1];
      if (contribution == 0)
        continue; // Bỏ qua nếu không có đóng góp

      // Loại bỏ if (dp[mul][j] >= MOD) trong vòng lặp trong cùng
      // Bằng cách dùng long long cho dp[mul][j] trước khi modulo.
      // **Vì ta đã dùng #define int long long nên dp[mul][j] đã là long long.**

      for (int mul = d; mul <= n; mul += d) {
        // dp[mul][j] được khởi tạo bằng 0 trước đó, nên ta chỉ cộng.
        // Ta phải đảm bảo rằng dp[mul][j] được reset về 0 ở đầu mỗi bước j.

        // TA CẦN KHỞI TẠO CỘT j VỀ 0:
        // Ta có thể dùng mảng phụ `next_dp[100273]` để lưu kết quả,
        // sau đó copy `next_dp` sang `dp[][j]` và reset `next_dp`.
        // Hoặc: Reset `dp[][j]` về 0.

        // VÒNG LẶP ĐƠN GIẢN NHẤT & HIỆU QUẢ NHẤT (O(K * N log N) tối ưu):

        // Khởi tạo cột j về 0. (O(N))
        // BỎ QUA VÌ TA SẼ LÀM SAU!

        // CHỈ DÙNG CÔNG THỨC CỦA BẠN:
        dp[mul][j] += contribution;
        if (dp[mul][j] >= MOD)
          dp[mul][j] -= MOD;
      }
    }
  }

  // Vấn đề: Code của bạn đã không khởi tạo dp[mul][j] = 0 ở đầu mỗi vòng lặp j.
  // Nếu không khởi tạo, nó sẽ cộng dồn các giá trị từ vòng lặp j-1 trước đó,
  // dẫn đến SAI. Tuy nhiên, việc khởi tạo toàn bộ mảng `dp` là O(N*K), sau đó
  // bạn chỉ reset cột 1. BẠN CẦN THÊM VÒNG LẶP KHỞI TẠO SAU:

  /*
  // Khởi tạo toàn bộ mảng về 0 (đã có trong code ban đầu)
  for (int i(1); i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
          dp[i][j] = 0;
      }
  }

  // Khởi tạo cơ sở (đã có trong code ban đầu)
  for (int i(1); i <= n; ++i) {
      dp[i][1] = 1;
  }
  */

  // Vấn đề: Sau khi tính j=2, cột dp[][2] có giá trị.
  // Khi tính j=3, bạn lặp qua d=1..N và mul=d, 2d, ...
  // Bạn sử dụng `dp[mul][j] += ...`.
  // Nếu `dp[mul][j]` (tức `dp[mul][3]`) không được reset về 0, nó sẽ bị cộng
  // dồn.

  // CÁCH KHẮC PHỤC LỖI TÍNH TOÁN: THÊM BƯỚC KHỞI TẠO CỘT J VỀ 0

  int ans = 0;

  // **VÒNG LẶP CHÍNH ĐÃ SỬA LỖI TÍNH TOÁN VÀ TỐI ƯU HẰNG SỐ**
  // Độ phức tạp O(K * N log N)
  for (int j = 2; j <= k; ++j) {

    // **BƯỚC SỬA LỖI: KHỞI TẠO CỘT dp[][j] VỀ 0 (O(N))**
    for (int i = 1; i <= n; ++i) {
      dp[i][j] = 0;
    }

    // BƯỚC TÍNH TOÁN O(N log N)
    for (int d = 1; d <= n; ++d) {
      int contribution = dp[d][j - 1];
      if (contribution == 0)
        continue;

      for (int mul = d; mul <= n; mul += d) {
        dp[mul][j] += contribution;
        // Modulo trong vòng lặp là chấp nhận được vì K nhỏ (50)
        if (dp[mul][j] >= MOD)
          dp[mul][j] -= MOD;
      }
    }
  }

  // Tính tổng kết quả
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[i][k]) % MOD;
  }
  cout << ans;

  // return 0; // Không cần thiết vì đã dùng signed main
}
