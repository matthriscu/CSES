#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  multiset<int, greater<int>> tickets;

  int n, m;
  cin >> n >> m;

  for (int i = 0, h; i < n; ++i) {
    cin >> h;
    tickets.insert(h);
  }

  for (int i = 0, t; i < m; ++i) {
    cin >> t;

    auto it = tickets.lower_bound(t);

    if (it != tickets.end()) {
      cout << *it << '\n';
      tickets.erase(it);
    } else
      cout << "-1\n";
  }
}
