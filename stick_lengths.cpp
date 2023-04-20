#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  sort(v.begin(), v.end());

  cout << transform_reduce(
              v.begin(), v.end(), 0LL, plus{},
              [median = v[n / 2]](int x) { return abs(x - median); })
       << '\n';
}
