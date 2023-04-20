#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int &x : v)
    cin >> x;

  multiset<int, greater<int>> low;
  multiset<int> high;
  long long low_sum = 0, high_sum = 0;

  vector<int> copy(v.begin(), v.begin() + k);
  sort(copy.begin(), copy.end());
  auto mid = copy.begin() + (k + 1) / 2;

  low.insert(copy.begin(), mid);
  low_sum = reduce(copy.begin(), mid, 0LL);
  high.insert(mid, copy.begin() + k);
  high_sum = reduce(mid, copy.begin() + k, 0LL);

  cout << high_sum - low_sum + (k % 2 ? *low.begin() : 0) << ' ';

  for (int i = k; i < n; ++i) {
    if (v[i] <= *low.begin()) {
      low.insert(v[i]);
      low_sum += v[i];
    } else {
      high.insert(v[i]);
      high_sum += v[i];
    }

    auto it = low.find(v[i - k]);
    if (it != low.end()) {
      low.erase(it);
      low_sum -= v[i - k];
    } else {
      high.erase(high.find(v[i - k]));
      high_sum -= v[i - k];
    }

    while (low.size() < (k + 1) / 2) {
      it = high.begin();

      low_sum += *it;
      high_sum -= *it;

      low.insert(*it);
      high.erase(it);
    }

    while (high.size() < k / 2) {
      it = low.begin();

      low_sum -= *it;
      high_sum += *it;

      low.erase(it);
      high.insert(*it);
    }

    cout << high_sum - low_sum + (k % 2 ? *low.begin() : 0) << ' ';
  }

  cout << '\n';
}
