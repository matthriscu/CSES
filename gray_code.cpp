#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<bool> visited(1 << n, false);
  vector<int> ans;

  function<bool(int, int)> dfs = [&](int current, int depth) {
    visited[current] = true;

    if (depth == (1 << n)) {
      ans.push_back(current);
      return true;
    }

    for (int i = 0; i < n; ++i) {
      int next = current ^ (1 << i);

      if (!visited[next] && dfs(next, depth + 1)) {
        ans.push_back(current);
        return true;
      }
    }

    return false;
  };

  dfs(0, 1);

  for (int x : ans) {
    for (int i = n - 1; i >= 0; --i)
      cout << (bool)(x & (1 << i));
    cout << '\n';
  }
}
