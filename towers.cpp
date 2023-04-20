#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  map<int, int> s;

  for (int i = 0, x; i < n; ++i) {
    cin >> x;

    auto it = s.upper_bound(x);

    if (it != s.end()) {
      if (it->second == 1)
        s.erase(it);
      else
        --it->second;
    }

    ++s[x];
  }

  cout << transform_reduce(s.begin(), s.end(), 0, plus{}, [](auto p) {
    return p.second;
  }) << '\n';
}
