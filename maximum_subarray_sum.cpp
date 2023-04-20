#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  long long best = INT_MIN;

  for (long long i = 0, current = 0, x; i < n; ++i) {
    cin >> x;
    current = max(x, current + x);
    best = max(current, best);
  }

  cout << best << '\n';
}
