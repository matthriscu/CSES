#include <bits/stdc++.h>
#include <ios>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> movies(n);
  for (auto &[start, end] : movies)
    cin >> start >> end;

  sort(movies.begin(), movies.end(), [](auto a, auto b) {
    if (a.second == b.second)
      return a.first < b.first;

    return a.second < b.second;
  });

  multiset<int, greater<int>> members;
  for (int i = 0; i < k; ++i)
    members.insert(0);

  int ans = 0;
  for (auto [start, end] : movies) {
    auto it = members.lower_bound(start);

    if (it != members.end()) {
      ++ans;
      members.erase(it);
      members.insert(end);
    }
  }

  cout << ans << '\n';
}
