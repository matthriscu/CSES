#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n - 1);
  for (int &x : v)
    cin >> x;

  if (find(v.begin(), v.end(), 1) == v.end()) {
    cout << "1\n";
    return 0;
  }

  auto left = v.begin(), right = v.end();

  while (next(left) != right) {
    size_t dist = distance(left, right) / 2;
    auto mid = left + dist;

    nth_element(left, mid, right);

    if (*mid != distance(v.begin(), mid) + 1)
      right = mid;
    else
      left = mid;
  }

  cout << *left + 1 << '\n';
}
