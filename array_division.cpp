#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  long long mx = *max_element(v.begin(), v.end()),
            s = reduce(v.begin(), v.end(), 0LL), step = 1, ans = s;

  for (; step < (s - mx); step <<= 1)
    ;

  auto check = [&](long long capacity) {
    long long subarrays = 1, s = 0;

    for (int x : v)
      if (s + x <= capacity)
        s += x;
      else {
        if (++subarrays > k)
          return false;

        s = x;
      }

    return true;
  };

  for (; step; step >>= 1)
    if (ans - step >= mx && check(ans - step))
      ans -= step;

  cout << ans << '\n';
}
