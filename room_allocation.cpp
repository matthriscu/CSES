#include <bits/stdc++.h>
using namespace std;

struct range {
  int start, end, index;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<range> customers(n);
  for (int i = 0; i < n; ++i) {
    cin >> customers[i].start >> customers[i].end;
    customers[i].index = i;
  }

  sort(customers.begin(), customers.end(), [](auto c1, auto c2) {
    if (c1.end == c2.end)
      return c1.start < c2.start;
    return c1.end < c2.end;
  });

  int k = 0;
  set<pair<int, int>, greater<pair<int, int>>> rooms;
  vector<int> ans(n);

  for (auto [start, end, index] : customers) {
    auto it = rooms.upper_bound({start, -1});

    if (it == rooms.end())
      ans[index] = ++k;
    else {
      ans[index] = it->second;
      rooms.erase(it);
    }

    rooms.insert({end, ans[index]});
  }

  cout << k << '\n';
  for (int room : ans)
    cout << room << ' ';
  cout << '\n';
}
