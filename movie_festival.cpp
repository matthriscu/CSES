#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> movies(n);

  for (auto &[start, end] : movies)
    cin >> start >> end;

  sort(movies.begin(), movies.end(), [](auto p1, auto p2) {
    if (p1.second == p2.second)
      return p1.first < p2.first;
    return p1.second < p2.second;
  });

  int last_end = -1, ans = 0;

  for (auto [start, end] : movies)
    if (start >= last_end) {
      last_end = end;
      ++ans;
    }

  cout << ans << '\n';
}
