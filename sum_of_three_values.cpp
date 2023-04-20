#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i)
    for (int j = i + 1, k = n - 1; j < k;) {
      if (v[j].first + v[k].first == x - v[i].first) {
        cout << v[i].second << ' ' << v[j].second << ' ' << v[k].second << '\n';
        return 0;
      } else if (v[j].first + v[k].first < x - v[i].first)
        ++j;
      else
        --k;
    }

  cout << "IMPOSSIBLE\n";
}
