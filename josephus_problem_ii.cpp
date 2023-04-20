#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  size_t n, k;
  cin >> n >> k;

  ordered_set s;
  for (size_t i = 1; i <= n; ++i)
    s.insert(i);

  size_t idx = 0;
  while (!s.empty()) {
    idx = (idx + k) % s.size();

    auto it = s.find_by_order(idx);
    cout << *it << ' ';

    s.erase(it);
  }

  cout << '\n';
}
