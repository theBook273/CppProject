#include <iostream>
#include <numeric>
#include <vector>

#define int long long

using namespace std;

const int MAX_A = 200005;
const int MOD = 1e9 + 7;

int a[MAX_A];
int dp[MAX_A];
int last_sum[MAX_A];
int spf[MAX_A];

int add(int x, int y) { return (x + y) % MOD; }
int sub(int x, int y) { return (x - y + MOD) % MOD; }

void sieve() {
  iota(spf, spf + MAX_A, 0);
  for (int i = 2; i * i < MAX_A; i++) {
    if (spf[i] == i) { // i is prime
      for (int j = i * i; j < MAX_A; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}

vector<int> get_prime_factors(int n) {
  vector<int> factors;
  if (n == 1)
    return factors;
  while (n != 1) {
    int p = spf[n];
    factors.push_back(p);
    while (n > 1 && n % p == 0) {
      n /= p;
    }
  }
  return factors;
}

vector<int> get_all_divisors(int n) {
  vector<int> divisors;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i * i != n) {
        divisors.push_back(n / i);
      }
    }
  }
  return divisors;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve();

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }

  dp[0] = 1;
  vector<int> divisors_a0 = get_all_divisors(a[0]);
  for (int d : divisors_a0) {
    last_sum[d] = add(last_sum[d], dp[0]);
  }

  for (int i = 1; i < n; i++) {
    vector<int> p_factors = get_prime_factors(a[i]);
    int k = p_factors.size();
    int current_sum = 0;

    // Use Principle of Inclusion-Exclusion to calculate dp[i]
    // dp[i] = sum of dp[j] for j < i where gcd(a[i], a[j]) != 1
    for (int j = 1; j < (1 << k); j++) {
      int d = 1;
      int set_bits = 0;
      for (int bit = 0; bit < k; bit++) {
        if ((j >> bit) & 1) {
          d *= p_factors[bit];
          set_bits++;
        }
      }
      if (set_bits % 2 == 1) {
        current_sum = add(current_sum, last_sum[d]);
      } else {
        current_sum = sub(current_sum, last_sum[d]);
      }
    }
    dp[i] = current_sum;

    // Update last_sum with the new dp[i] for all divisors of a[i]
    vector<int> divisors_ai = get_all_divisors(a[i]);
    for (int d : divisors_ai) {
      last_sum[d] = add(last_sum[d], dp[i]);
    }
  }

  cout << dp[n - 1] << endl;

  return 0;
}
