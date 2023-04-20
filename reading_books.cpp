#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  long long sum = 0;
  int mx = 0;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    sum += x;
    mx = max(x, mx);
  }

  cout << max(2LL * mx, sum) << '\n';
}
