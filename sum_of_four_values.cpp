#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  unordered_map<int, pair<int, int>> pairs;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto it = pairs.find(x - v[i] - v[j]);

      if (it != pairs.end()) {
        cout << i + 1 << ' ' << j + 1 << ' ' << it->second.first + 1 << ' '
             << it->second.second + 1 << '\n';
        return 0;
      }
    }

    for (int j = 0; j < i; ++j)
      pairs[v[i] + v[j]] = {i, j};
  }

  cout << "IMPOSSIBLE\n";
}
