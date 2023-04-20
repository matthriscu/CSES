#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i;
  }

  sort(v.begin(), v.end(), [](auto p1, auto p2) {
    if (p1.first.first == p2.first.first)
      return p1.first.second > p2.first.second;
    return p1.first.first < p2.first.first;
  });

  ordered_set s;
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; --i) {
    ans[v[i].second] = s.order_of_key({v[i].first.second + 1, -1});
    s.insert({v[i].first.second, i});
  }

  for (bool x : ans)
    cout << x << ' ';
  cout << '\n';

  s.clear();

  for (int i = 0; i < n; ++i) {
    ans[v[i].second] = i - s.order_of_key({v[i].first.second, -1});
    s.insert({v[i].first.second, i});
  }

  for (bool x : ans)
    cout << x << ' ';
  cout << '\n';
}
