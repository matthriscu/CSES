#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, t;
  cin >> n >> t;

  vector<int> times(n);
  for (int &x : times)
    cin >> x;

  auto check = [&](long long time) {
    long long s = 0;

    for (int x : times) {
      s += time / x;

      if (s >= t)
        return true;
    }

    return false;
  };

  long long ans = 1LL * *max_element(times.begin(), times.end()) * t, step = 1;

  for (; step < ans; step <<= 1)
    ;

  for (; step; step >>= 1)
    if (ans - step >= 0 && check(ans - step))
      ans -= step;

  cout << ans << '\n';
}
