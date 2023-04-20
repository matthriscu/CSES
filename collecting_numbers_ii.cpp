#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> index_of(n), p(n);

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    index_of[p[i]] = i;
  }

  auto contribution = [&](int x) {
    return x > 0 && x < n ? index_of[x] < index_of[x - 1] : 0;
  };

  int ans = 1;
  for (int i = 1; i < n; ++i)
    ans += contribution(i);

  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a;
    --b;

    map<int, int> updates;

    for (int x : {p[a], p[a] + 1, p[b], p[b] + 1})
      updates[x] = contribution(x);

    swap(p[a], p[b]);

    index_of[p[a]] = a;
    index_of[p[b]] = b;

    for (auto [x, c] : updates)
      ans += contribution(x) - c;

    cout << ans << '\n';
  }
}
