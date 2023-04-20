#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  deque<int> p(n);
  for (int &e : p)
    cin >> e;

  sort(p.begin(), p.end());

  int ans = 0;
  while (p.size() > 1) {
    if (p.front() + p.back() <= x)
      p.pop_front();

    ++ans;
    p.pop_back();
  }

  cout << ans + p.size() << '\n';
}
