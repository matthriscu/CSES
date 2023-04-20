#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, n;
  cin >> x >> n;

  set<int> lights{0, x};
  multiset<int, greater<int>> dist;

  dist.insert(x);

  while (n--) {
    int pos;
    cin >> pos;

    auto nxt = lights.lower_bound(pos), prv = prev(nxt);

    dist.erase(dist.lower_bound(*nxt - *prv));

    dist.insert(pos - *prv);
    dist.insert(*nxt - pos);
    lights.insert(pos);

    cout << *dist.begin() << ' ';
  }

  cout << '\n';
}
