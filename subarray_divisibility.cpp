#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  v[0] = 1;

  long long sum = 0;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    sum += x;
    ++v[((sum % n) + n) % n];
  }

  cout << transform_reduce(v.begin(), v.end(), 0LL, plus{}, [](int x) {
    return 1LL * x * (x - 1) / 2;
  }) << '\n';
}
