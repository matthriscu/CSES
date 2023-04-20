#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  long long current = 0, ans = 0;
  map<long long, int> sums;
  sums[0] = 1;

  for (int i = 0, elem; i < n; ++i) {
    cin >> elem;
    current += elem;

    auto it = sums.find(current - x);
    ans += it != sums.end() ? it->second : 0;

    ++sums[current];
  }

  cout << ans << '\n';
}
