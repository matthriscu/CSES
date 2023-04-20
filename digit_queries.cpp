#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long p10[19];
  p10[0] = 1;

  for (int i = 1; i <= 18; ++i)
    p10[i] = 10 * p10[i - 1];

  int q;
  cin >> q;

  while (q--) {
    long long k;
    cin >> k;

    int digits = 1;
    long long n = 9;

    while (k > digits * n) {
      k -= digits * n;
      ++digits;
      n *= 10;
    }

    n = p10[digits - 1] + k / digits;
    k %= digits;

    if (k == 0) {
      k = digits;
      --n;
    }

    cout << n / p10[digits - k] % 10 << '\n';
  }
}
