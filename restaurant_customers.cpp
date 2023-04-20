#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int>> events(2 * n);

  for (int i = 0; i < n; ++i) {
    cin >> events[2 * i].first >> events[2 * i + 1].first;

    events[2 * i].second = 1;
    events[2 * i + 1].second = -1;
  }

  sort(events.begin(), events.end());

  int current = 0, best = 0;

  for (auto [t, v] : events) {
    current += v;
    best = max(current, best);
  }

  cout << best << '\n';
}
