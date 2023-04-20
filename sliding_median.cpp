#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  ordered_set s;
  for (int i = 0; i < k; ++i)
    s.insert(v[i]);

  cout << *s.find_by_order((k - 1) / 2) << ' ';

  for (int i = k; i < n; ++i) {
    s.insert(v[i]);
    s.erase(s.find_by_order(s.order_of_key(v[i - k])));

    cout << *s.find_by_order((k - 1) / 2) << ' ';
  }

  cout << '\n';
}
